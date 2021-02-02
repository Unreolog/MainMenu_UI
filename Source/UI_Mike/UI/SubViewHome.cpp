// Fill out your copyright notice in the Description page of Project Settings.


#include "SubViewHome.h"
#include "Components/CanvasPanelSlot.h"

USubViewHome::USubViewHome(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}


void USubViewHome::NativePreConstruct()
{
	
	// Initialization Slots
	ButtonsSectionSlot = Cast<UCanvasPanelSlot>(ButtonsSection->Slot);
	ButtonSlot_1 = Cast<UCanvasPanelSlot>(Button_0->Slot);
	ButtonSlot_2 = Cast<UCanvasPanelSlot>(Button_1->Slot);
	ButtonSlot_3 = Cast<UCanvasPanelSlot>(Button_2->Slot);
	ButtonSlot_4 = Cast<UCanvasPanelSlot>(Button_3->Slot);
	PreviewSwitcherSlot = Cast<UCanvasPanelSlot>(PreviewSwitcher->Slot);
	PreviewSlot_0 = Cast<UWidgetSwitcherSlot>(Preview_0->Slot);
	PreviewSlot_1 = Cast<UWidgetSwitcherSlot>(Preview_1->Slot);
	PreviewSlot_2 = Cast<UWidgetSwitcherSlot>(Preview_2->Slot);
	PreviewSlot_3 = Cast<UWidgetSwitcherSlot>(Preview_3->Slot);
	PreviewSlot_4 = Cast<UWidgetSwitcherSlot>(Preview_4->Slot);


	if (SemiAutoInstall) { SetStartingProperties(); }

	ButtonsSectionSlot->SetPosition(ButtonSectionPosition);
	ButtonsSectionSlot->SetSize(ButtonSectionSize);
	PreviewSwitcherSlot->SetPosition(PreviewSwitcherPosition);

	
	
}


void USubViewHome::SetStartingProperties()
{
	ButtonSectionPosition = FVector2D(0, 10);
	ButtonSectionSize = FVector2D(870, 580);
	
	PreviewSwitcherPosition = FVector2D(935, 18);
}