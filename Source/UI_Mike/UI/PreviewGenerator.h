#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/Image.h"
#include "Components/Overlay.h"
#include "Components/OverlaySlot.h"
#include "Components/TextBlock.h"
#include "PreviewGenerator.generated.h"


USTRUCT(Blueprintable)
struct FWidgetSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D OverlaySize;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture* ImageFile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D ImageSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture* IconFile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D IconSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText DescriptionTitle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DefaultValue="24", DisplayName="Font Size"))
	int32 DescriptionTitleSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowedClasses="Font", DisplayName="Font Family"))
	UObject* DescriptionTitleFont;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText DescriptionText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DefaultValue="12", DisplayName="Font Size"))
	int32 DescriptionTextSize;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowedClasses="Font", DisplayName="Font Family"))
	UObject* DescriptionTextFont;
};


/**
 * 
 */
UCLASS()
class UPreviewGenerator : public UUserWidget
{
	GENERATED_BODY()


public:
	UPreviewGenerator(const FObjectInitializer& ObjectInitializer);
	
	virtual void NativePreConstruct() override;

	void SetStartProperties();
	
	// Binding widgets
	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* WCanvasPanel;

	UPROPERTY(meta = (BindWidget))
	UOverlay* WOverlay;

	UPROPERTY(meta = (BindWidget))
	UImage* PreviewImage;
	
	UPROPERTY(meta = (BindWidget))
	UImage* Icon;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* DescriptionTitle; 
	
	UPROPERTY(meta = (BindWidget))
	UTextBlock* DescriptionText;


	// Creating slots
	UPROPERTY()
	UCanvasPanelSlot* WOverlaySlot;

	UPROPERTY()
	UOverlaySlot* PreviewImageSlot;
	
	UPROPERTY()
	UOverlaySlot* IconSlot;
	
	UPROPERTY()
	UOverlaySlot* DescriptionTitleSlot;
	
	UPROPERTY()
	UOverlaySlot* DescriptionTextSlot;


	// Creating structs
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Button Widget")
	bool SemiAutoInstall;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Button Widget")
	FWidgetSettings WidgetSettings;
};
