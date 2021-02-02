#include "ButtonGenerator.h"
#include "Blueprint/WidgetTree.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/SlateWrapperTypes.h"


UButtonGenerator::UButtonGenerator(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}


void UButtonGenerator::NativePreConstruct()
{
	Super::NativePreConstruct();

	/*
	 * Initializing slots
	 */
	OverlaySlot = Cast<UCanvasPanelSlot>(WOverlay->Slot);
	BorderSlot = Cast<UOverlaySlot>(WBorder->Slot);
	ButtonSlot = Cast<UOverlaySlot>(WButton->Slot);
	DarkOverlaySlot = Cast<UOverlaySlot>(DarkOverlay->Slot);
	FocusedOverlaySlot = Cast<UOverlaySlot>(FocusedOverlay->Slot);
	TextAreaSlot = Cast<UOverlaySlot>(TextArea->Slot);
	CategoryTitleSlot = Cast<UVerticalBoxSlot>(CategoryTitle->Slot);
	MainTitleSlot = Cast<UVerticalBoxSlot>(MainTitle->Slot);


	/*
	* Initializing material instances for VFX
	*/
	// Instance Material for fading on/out color
	VisualEffects.FadeOutMatInstance = UMaterialInstanceDynamic::Create(VisualEffects.FadeOutMat, this);
	VisualEffects.FadeOutMatInstance->SetTextureParameterValue(FName("ImageButton"), ButtonStyle.ImageFile);

	// Instance Material for overlays
	// Black overlay
	VisualEffects.OverlayBlackMatInstance = UMaterialInstanceDynamic::Create(VisualEffects.OverlayMat, this);
	VisualEffects.OverlayBlackMatInstance->SetScalarParameterValue(FName("Power"), 2.0);
	VisualEffects.OverlayBlackMatInstance->SetVectorParameterValue(FName("Color"), FLinearColor(0, 0, 0, 1));

	// Red overlay
	VisualEffects.OverlayRedMatInstance = UMaterialInstanceDynamic::Create(VisualEffects.OverlayMat, this);
	VisualEffects.OverlayRedMatInstance->SetScalarParameterValue(FName("Power"), 1.0);
	VisualEffects.OverlayRedMatInstance->SetVectorParameterValue(FName("Color"), FLinearColor(0.439657, 0.014444, 0.042311, 1));


	if (SemiAutoInstall)
	{
		SetStartingProperties();
	}

	/*
	 * Initializing widgets properties
	 */
	// Button properties
	// Normal button style
	WButton->WidgetStyle.Normal.SetResourceObject(VisualEffects.FadeOutMatInstance);
	WButton->WidgetStyle.Normal.SetImageSize(ButtonStyle.NormalImageSize);
	WButton->WidgetStyle.Normal.DrawAs = ESlateBrushDrawType::Image;

	// Hovered button style
	WButton->WidgetStyle.Hovered.SetResourceObject(VisualEffects.FadeOutMatInstance);
	WButton->WidgetStyle.Hovered.SetImageSize(ButtonStyle.HoveredImageSize);
	WButton->WidgetStyle.Hovered.DrawAs = ESlateBrushDrawType::Image;

	// Pressed button style
	WButton->WidgetStyle.Pressed.SetResourceObject(VisualEffects.FadeOutMatInstance);
	WButton->WidgetStyle.Pressed.SetImageSize(ButtonStyle.NormalImageSize);
	WButton->WidgetStyle.Pressed.DrawAs = ESlateBrushDrawType::Image;
	WButton->WidgetStyle.PressedSlateSound.SetResourceObject(SoundEffects.PressedSound);

	// Common button style
	WButton->WidgetStyle.SetNormalPadding(FMargin(0));
	WButton->WidgetStyle.SetPressedPadding(FMargin(0));

	// Create Button Events
	WButton->OnHovered.AddDynamic(this, &UButtonGenerator::OnHovered);
	WButton->OnUnhovered.AddDynamic(this, &UButtonGenerator::OnUnhovered);
	WButton->OnPressed.AddDynamic(this, &UButtonGenerator::OnPressed);


	// Border properties
	WBorder->SetPadding(FMargin(0));
	WBorder->SetBrushColor(FLinearColor(1, 1, 1, 0.2));
	WBorder->SetVisibility(ESlateVisibility::SelfHitTestInvisible);

	// Dark overlay properties
	DarkOverlay->Brush.SetResourceObject(VisualEffects.OverlayBlackMatInstance);
	DarkOverlay->SetVisibility(ESlateVisibility::SelfHitTestInvisible);

	// Focused overlay properties
	FocusedOverlay->Brush.SetResourceObject(VisualEffects.OverlayRedMatInstance);
	FocusedOverlay->SetColorAndOpacity(FLinearColor(1, 1, 1, 0));
	FocusedOverlay->SetVisibility(ESlateVisibility::SelfHitTestInvisible);

	// TextArea properties
	TextArea->SetVisibility(ESlateVisibility::HitTestInvisible);

	// Category Title properties
	CategoryTitle->SetText(TextTitles.CategoryTitleText.ToUpper());
	CategoryTitle->SetColorAndOpacity(TextTitles.ColorCategoryTitle);
	CategoryTitle->SetFont(FSlateFontInfo(TextTitles.TextFont, TextTitles.CategoryTitleTextSize));

	// Main Title properties
	MainTitle->SetText(TextTitles.MainTitleText.ToUpper());
	MainTitle->SetColorAndOpacity(TextTitles.ColorMainTitle);
	MainTitle->SetFont(FSlateFontInfo(TextTitles.TextFont, TextTitles.MainTitleTextSize));

	/*
	 * Initializing Slots properties
	 */
	// Overlay Slot
	OverlaySlot->SetAutoSize(true);

	// Border Slot
	BorderSlot->SetHorizontalAlignment(HAlign_Fill);
	BorderSlot->SetVerticalAlignment(VAlign_Fill);

	// Button Slot
	ButtonSlot->SetPadding(FMargin(1));
	ButtonSlot->SetHorizontalAlignment(HAlign_Center);
	ButtonSlot->SetVerticalAlignment(VAlign_Center);

	// Dark Overlay Slot
	DarkOverlaySlot->SetPadding(FMargin(1));
	DarkOverlaySlot->SetHorizontalAlignment(HAlign_Fill);
	DarkOverlaySlot->SetVerticalAlignment(VAlign_Fill);

	// Focused Overlay Slot
	FocusedOverlaySlot->SetPadding(FMargin(1));
	FocusedOverlaySlot->SetHorizontalAlignment(HAlign_Fill);
	FocusedOverlaySlot->SetVerticalAlignment(VAlign_Fill);

	// TextArea Slots
	TextAreaSlot->SetHorizontalAlignment(HAlign_Left);
	TextAreaSlot->SetVerticalAlignment(VAlign_Bottom);


	CategoryTitleSlot->SetPadding(FMargin(0, 0, 0, 4));
	CategoryTitleSlot->SetSize(ESlateSizeRule::Automatic);
	CategoryTitleSlot->SetHorizontalAlignment(HAlign_Left);
	CategoryTitleSlot->SetVerticalAlignment(VAlign_Bottom);

	MainTitleSlot->SetSize(ESlateSizeRule::Automatic);
	MainTitleSlot->SetHorizontalAlignment(HAlign_Left);
	MainTitleSlot->SetVerticalAlignment(VAlign_Bottom);

	MainTitle->SetAutoWrapText(TextTitles.AutoWrap);
}


// Mouse Events
void UButtonGenerator::OnUnhovered()
{
	PlayAnimation(FocusedAnimation, 0, 1, EUMGSequencePlayMode::Reverse);
	WButton->WidgetStyle.Normal.SetImageSize(ButtonStyle.NormalImageSize);
}


void UButtonGenerator::OnPressed()
{
	PressedCDispatcher.Broadcast(IDButton);
}


void UButtonGenerator::OnHovered()
{
	PlayAnimation(FocusedAnimation, 0, 1, EUMGSequencePlayMode::Forward);
	WButton->WidgetStyle.Normal.SetImageSize(ButtonStyle.HoveredImageSize);
	PlaySound(SoundEffects.HoveredSound);
	HoveredCDispatcher.Broadcast(IDButton);
}


// Set widget setting in semi-auto mode 
void UButtonGenerator::SetStartingProperties()
{
	if (IsSmallButton)
	{
		ButtonStyle.NormalImageSize = FVector2D(200.0, 274);
		ButtonStyle.HoveredImageSize = FVector2D(208, 290);
		TextTitles.CategoryTitleTextSize = 8;
		TextTitles.MainTitleTextSize = 14;
		TextAreaSlot->SetPadding(FMargin(16, 0, 0, 16));
	}
	else
	{
		ButtonStyle.NormalImageSize = FVector2D(400, 560);
		ButtonStyle.HoveredImageSize = FVector2D(412, 586);
		TextTitles.CategoryTitleTextSize = 8;
		TextTitles.MainTitleTextSize = 24;
		TextAreaSlot->SetPadding(FMargin(24, 0, 0, 24));
	}

	TextTitles.CategoryTitleText = TextTitles.CategoryTitleText.IsEmpty()
		                               ? FText::FromString(TEXT("Favorite")).ToUpper()
		                               : TextTitles.CategoryTitleText.ToUpper();
	TextTitles.ColorCategoryTitle = FLinearColor(1, 0.014444, 0.090842, 1);

	TextTitles.MainTitleText = TextTitles.MainTitleText.IsEmpty()
		                           ? FText::FromString(TEXT("Quick Game")).ToUpper()
		                           : TextTitles.MainTitleText.ToUpper();
	TextTitles.ColorMainTitle = FLinearColor(1, 1, 1, 1);
}
