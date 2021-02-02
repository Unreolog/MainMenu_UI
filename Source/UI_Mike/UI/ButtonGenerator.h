#pragma once

#include "Blueprint/UserWidget.h"
#include "Components/Border.h"
#include "Components/BorderSlot.h"
#include "Components/Button.h"
#include "Components/ButtonSlot.h"
#include "Components/CanvasPanel.h"
#include "Components/Image.h"
#include "Components/Overlay.h"
#include "Components/OverlaySlot.h"
#include "Components/SizeBox.h"
#include "Components/SizeBoxSlot.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"
#include "Sound/SoundCue.h"
#include "ButtonGenerator.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHoveredDispatcher, int32, HoveredButtonID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPressedDispatcher, int32, PressedButtonID);


// Struct for setting a source image file and styles of button 
USTRUCT(Blueprintable)
struct FButtonStyles
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture* ImageFile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D NormalImageSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D HoveredImageSize;
};


// Struct for creating visual effects material instances 
USTRUCT(Blueprintable)
struct FMaterialVisualEffects
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMaterial* FadeOutMat;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UMaterialInstanceDynamic* FadeOutMatInstance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMaterial* OverlayMat;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UMaterialInstanceDynamic* OverlayBlackMatInstance;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UMaterialInstanceDynamic* OverlayRedMatInstance;
};


// Struct for creating sound effects for swap, scroll, and click 
USTRUCT(Blueprintable)
struct FSoundEffects
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USoundCue* HoveredSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USoundCue* PressedSound;
};


// Struct for creating text titles
USTRUCT(Blueprintable)
struct FTextTitles
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (MultiLine = true))
	FText CategoryTitleText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="Font Color"))
	FLinearColor ColorCategoryTitle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="Font Size"))
	int32 CategoryTitleTextSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (MultiLine = true))
	FText MainTitleText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="Font Color"))
	FLinearColor ColorMainTitle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="Font Size"))
	int32 MainTitleTextSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowedClasses="Font", DisplayName="Font Family"))
	UObject* TextFont;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool AutoWrap;
};


UCLASS()
class UButtonGenerator : public UUserWidget
{
	GENERATED_BODY()

public:
	UButtonGenerator(const FObjectInitializer& ObjectInitializer);

	void SetStartingProperties();

	virtual void NativePreConstruct() override;

	// Binding widgets
	UPROPERTY(Meta = (BindWidget))
	UCanvasPanel* WCanvasPanel;

	UPROPERTY(Meta = (BindWidget))
	UOverlay* WOverlay;

	UPROPERTY(Meta = (BindWidget))
	UBorder* WBorder;

	UPROPERTY(BlueprintReadOnly, Meta = (BindWidget))
	UButton* WButton;

	UPROPERTY(Meta = (BindWidget))
	UImage* DarkOverlay;

	UPROPERTY(Meta = (BindWidget))
	UImage* FocusedOverlay;

	UPROPERTY(Meta = (BindWidget))
	UVerticalBox* TextArea;

	UPROPERTY(Meta = (BindWidget))
	UTextBlock* CategoryTitle;

	UPROPERTY(Meta = (BindWidget))
	UTextBlock* MainTitle;


	// Binding slots
	UPROPERTY()
	UCanvasPanelSlot* OverlaySlot;

	UPROPERTY()
	UOverlaySlot* BorderSlot;

	UPROPERTY()
	UOverlaySlot* ButtonSlot;

	UPROPERTY()
	UOverlaySlot* DarkOverlaySlot;

	UPROPERTY()
	UOverlaySlot* FocusedOverlaySlot;

	UPROPERTY()
	UOverlaySlot* TextAreaSlot;

	UPROPERTY()
	UVerticalBoxSlot* CategoryTitleSlot;

	UPROPERTY()
	UVerticalBoxSlot* MainTitleSlot;


	// Setting structs
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Button Widget")
	bool SemiAutoInstall;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Button Widget")
	bool IsSmallButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Button Widget")
	int32 IDButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Button Widget")
	FButtonStyles ButtonStyle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Button Widget")
	FMaterialVisualEffects VisualEffects;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Button Widget")
	FSoundEffects SoundEffects;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Button Widget")
	FTextTitles TextTitles;




	// Animation
	UPROPERTY(meta = (BindWidgetAnim))
	UWidgetAnimation* FocusedAnimation;

	UFUNCTION(BlueprintCallable)
	void OnUnhovered();

	UFUNCTION(BlueprintCallable)
	void OnPressed();

	UFUNCTION(BlueprintCallable)
	void OnHovered();

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FHoveredDispatcher HoveredCDispatcher;

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FHoveredDispatcher PressedCDispatcher;

	
};
