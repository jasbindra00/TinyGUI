#include "GUICheckbox.h"

GUICheckbox::GUICheckbox(GUIInterface* parent):GUIElement(parent, GUIType::CHECKBOX,GUILayerType::CONTENT){
	//specific keys for elements

}
void GUICheckbox::ToggleChecked() {
	if (checked == true) {
		checked = false;
		OnNeutral();
	}
	else {
		checked = true;
		OnFocus();
	}
	CheckboxCallback();
}

void GUICheckbox::OnNeutral(){
	SetState(GUIState::NEUTRAL);
}
void GUICheckbox::OnHover(){
}
void GUICheckbox::OnClick(const sf::Vector2f& mousepos){
	ToggleChecked();
}
void GUICheckbox::OnLeave(){
}

void GUICheckbox::OnFocus(){
	SetState(GUIState::FOCUSED);
}

void GUICheckbox::OnRelease(){

}
void GUICheckbox::ReadIn(KeyProcessing::Keys& keys){
	GUIElement::ReadIn(keys);
	using GUIData::GUIStateData::GUIState;
	KeyProcessing::FillMissingKey(KeyProcessing::KeyPair{ "CHECKBOX_TYPE","ERROR" }, keys);
	std::string checkboxstr = keys.find("CHECKBOX_TYPE")->second;
	//default the checkboxtype if invalid
	if (checkboxstr == "CIRCLE") checkboxsquare = false;
	else checkboxstr = "SQUARE";
	std::string checkedtexture{ "GUICheckbox_Checked_" + checkboxstr + ".png" };
	std::string uncheckedtexture{ "GUICheckbox_Unchecked_" + checkboxstr + ".png" };
	GetVisual().GetStyle(GUIState::NEUTRAL).ReadIn(STYLE_ATTRIBUTE::BG_TEXTURE_NAME, std::move(uncheckedtexture));
	GetVisual().GetStyle(GUIState::FOCUSED).ReadIn(STYLE_ATTRIBUTE::BG_TEXTURE_NAME, std::move(checkedtexture));
	for (int i = 0; i < 3; ++i) GetVisual().GetStyle(static_cast<GUIState>(i)).ReadIn(STYLE_ATTRIBUTE::TEXT_STRING, "");

}


