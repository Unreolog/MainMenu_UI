#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanel.h"
#include "Components/HorizontalBox.h"
#include "Components/Image.h"
#include "Components/ScaleBox.h"
#include "Components/TextBlock.h"
#include "MainMenu.generated.h"


/**
* 
*/
UCLASS()
class UMainMenu : public UUserWidget
{
	GENERATED_BODY()


public:
	UMainMenu(const FObjectInitializer& ObjectInitializer);

	virtual void NativePreConstruct() override;

	// Widgets declaration
	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* WCanvasPanel;

	UPROPERTY(meta = (BindWidget))
	UScaleBox* BackgroundScaleBox;

	UPROPERTY(meta = (BindWidget))
	UImage* Background;

	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* PageSection;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UHorizontalBox* TabsSection;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Tab_0;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Tab_1;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Tab_2;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Tab_3;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UImage* FocusLine;

	UPROPERTY(meta = (BindWidget))
	UImage* PageIndicator;
};
