#pragma once

#include "CoreMinimal.h"

#include "ButtonGenerator.h"
#include "PreviewGenerator.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/CanvasPanel.h"
#include "Components/HorizontalBox.h"
#include "Components/Image.h"
#include "Components/ScaleBox.h"
#include "Components/TextBlock.h"
#include "Components/WidgetSwitcher.h"
#include "Components/WidgetSwitcherSlot.h"
#include "Blueprint/WidgetTree.h"


#include "SubViewHome.generated.h"


/**
* 
*/
UCLASS()
class USubViewHome : public UUserWidget
{
	GENERATED_BODY()

public:
	USubViewHome(const FObjectInitializer& ObjectInitializer);

	virtual void NativePreConstruct() override;


	// Widgets declaration
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UCanvasPanel* ButtonsSection;

	UPROPERTY(meta = (BindWidget))
	UButtonGenerator* Button_0;

	UPROPERTY(meta = (BindWidget))
	UButtonGenerator* Button_1;

	UPROPERTY(meta = (BindWidget))
	UButtonGenerator* Button_2;

	UPROPERTY(meta = (BindWidget))
	UButtonGenerator* Button_3;

	UPROPERTY(meta = (BindWidget))
	UButtonGenerator* Button_4;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UWidgetSwitcher* PreviewSwitcher;

	UPROPERTY(meta = (BindWidget))
	UPreviewGenerator* Preview_0;

	UPROPERTY(meta = (BindWidget))
	UPreviewGenerator* Preview_1;

	UPROPERTY(meta = (BindWidget))
	UPreviewGenerator* Preview_2;

	UPROPERTY(meta = (BindWidget))
	UPreviewGenerator* Preview_3;

	UPROPERTY(meta = (BindWidget))
	UPreviewGenerator* Preview_4;


	// Creating slots
	UPROPERTY()
	UCanvasPanelSlot* ButtonsSectionSlot;

	UPROPERTY()
	UCanvasPanelSlot* ButtonSlot_0;

	UPROPERTY()
	UCanvasPanelSlot* ButtonSlot_1;

	UPROPERTY()
	UCanvasPanelSlot* ButtonSlot_2;

	UPROPERTY()
	UCanvasPanelSlot* ButtonSlot_3;

	UPROPERTY()
	UCanvasPanelSlot* ButtonSlot_4;

	UPROPERTY()
	UCanvasPanelSlot* PreviewSwitcherSlot;

	UPROPERTY()
	UWidgetSwitcherSlot* PreviewSlot_0;

	UPROPERTY()
	UWidgetSwitcherSlot* PreviewSlot_1;
	
	UPROPERTY()
	UWidgetSwitcherSlot* PreviewSlot_2;

	UPROPERTY()
	UWidgetSwitcherSlot* PreviewSlot_3;

	UPROPERTY()
	UWidgetSwitcherSlot* PreviewSlot_4;


	// Functions
	void SetStartingProperties();

	
	// Declaration variables
	// Settings
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Preview Widget Settings")
	bool SemiAutoInstall;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Preview Widget Settings")
	FVector2D ButtonSectionPosition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Preview Widget Settings")
	FVector2D ButtonSectionSize;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Preview Widget Settings")
	FVector2D PreviewSwitcherPosition;


	// Variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UButtonGenerator*> Buttons;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UButtonGenerator*> ButtonsArray;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 LastButtonID;
};
