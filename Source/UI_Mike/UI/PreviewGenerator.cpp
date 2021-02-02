#include "PreviewGenerator.h"


UPreviewGenerator::UPreviewGenerator(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}


void UPreviewGenerator::NativePreConstruct()
{
	// Slots init
	WOverlaySlot = Cast<UCanvasPanelSlot>(WOverlay->Slot);
	PreviewImageSlot = Cast<UOverlaySlot>(PreviewImage->Slot);
	IconSlot = Cast<UOverlaySlot>(Icon->Slot);
	DescriptionTitleSlot = Cast<UOverlaySlot>(DescriptionTitle->Slot);
	DescriptionTextSlot = Cast<UOverlaySlot>(DescriptionText->Slot);

	
	if (SemiAutoInstall) { SetStartProperties(); }

	
	// Setting slots
	WOverlaySlot->SetSize(WidgetSettings.OverlaySize);

	PreviewImageSlot->SetHorizontalAlignment(HAlign_Left);
	PreviewImageSlot->SetVerticalAlignment(VAlign_Top);

	IconSlot->SetPadding(FMargin(3, 0, 0, 77));
	IconSlot->SetHorizontalAlignment(HAlign_Left);
	IconSlot->SetVerticalAlignment(VAlign_Bottom);

	DescriptionTitleSlot->SetPadding(FMargin(32, 0, 0, 68));
	DescriptionTitleSlot->SetHorizontalAlignment(HAlign_Fill);
	DescriptionTitleSlot->SetVerticalAlignment(VAlign_Bottom);

	DescriptionTextSlot->SetPadding(FMargin(34, 0, 0, 0));
	DescriptionTextSlot->SetHorizontalAlignment(HAlign_Fill);
	DescriptionTextSlot->SetVerticalAlignment(VAlign_Bottom);


	// Setting widgets
	PreviewImage->SetBrushResourceObject(WidgetSettings.ImageFile);
	PreviewImage->SetBrushSize(WidgetSettings.ImageSize);

	Icon->SetBrushResourceObject(WidgetSettings.IconFile);
	Icon->SetBrushSize(WidgetSettings.IconSize);

	DescriptionTitle->SetText(WidgetSettings.DescriptionTitle);
	DescriptionTitle->SetFont(FSlateFontInfo(WidgetSettings.DescriptionTitleFont, WidgetSettings.DescriptionTitleSize));

	DescriptionText->SetText(WidgetSettings.DescriptionText);
	DescriptionText->SetFont(FSlateFontInfo(WidgetSettings.DescriptionTextFont, WidgetSettings.DescriptionTextSize));
	DescriptionText->SetAutoWrapText(true);
	DescriptionText->SetMinDesiredWidth(680.f);
	
}


void UPreviewGenerator::SetStartProperties()
{
	WidgetSettings.OverlaySize = FVector2D(800, 711);
	WidgetSettings.ImageSize = FVector2D(800, 560);
	WidgetSettings.IconSize = FVector2D(20, 21);

	WidgetSettings.DescriptionTitle = WidgetSettings.DescriptionTitle.IsEmpty()
		                                  ? FText::FromString(TEXT("Quick Game")).ToUpper()
		                                  : WidgetSettings.DescriptionTitle.ToUpper();

	WidgetSettings.DescriptionText = WidgetSettings.DescriptionText.IsEmpty()
		                                 ? FText::FromString(TEXT("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Scelerisque hendrerit a, ornare scelerisque diam. Volutpat sed nunc ut aenean a faucibus augue posuere. Tortor tincidunt non elementum et ut blandit."))
		                                 : WidgetSettings.DescriptionText;

	WidgetSettings.DescriptionTitleSize = 24;
	WidgetSettings.DescriptionTextSize = 12;
}
