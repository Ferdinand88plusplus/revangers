#ifndef _ACT_EVENTS_H
#define _ACT_EVENTS_H

// Event codes...
enum actEventCodes {
	EV_CHANGE_MODE = ACI_MAX_EVENT + 1,
	EV_SET_MODE,
	EV_ACTIVATE_MENU,
	EV_CHANGE_SCREEN,
	EV_FULLSCR_CHANGE,
	EV_ACTIVATE_IINV,
	EV_DEACTIVATE_IINV,
	EV_ACTIVATE_MATRIX,
	EV_DEACTIVATE_MATRIX,
	EV_EVINCE_PALETTE,
	EV_INIT_MATRIX_OBJ,
	EV_INIT_SC_MATRIX_OBJ,
	EV_REDRAW,
	EV_CANCEL_MATRIX,
	EV_AUTO_MOVE_ITEMS,
	EV_SET_MECH_NAME,

	EV_NEXT_SHOP_AVI,
	EV_PREV_SHOP_AVI,

	EV_CHANGE_AVI_LIST,

	EV_BUY_ITEM,

	EV_SET_ITM_PICKUP,
	EV_SET_WPN_PICKUP,

	EV_ACTIVATE_SHOP_MENU,
	EV_CHOOSE_SHOP_ITEM,

	EV_NEXT_PHRASE,
	EV_START_SPEECH,
	EV_SHOW_QUESTS,
	EV_ASK_QUEST,

	EV_TRY_2_ENTER,
	EV_GET_CIRT,

	EV_TAKE_ELEECH,
	EV_GET_ELEECH,
	EV_ISCR_KEYTRAP,

	EV_LOCK_ISCREEN,
	EV_UNLOCK_ISCREEN,

	EV_SELL_MOVE_ITEM,
	EV_CHANGE_AVI_INDEX,

	EV_TELEPORT,

	EV_INIT_BUTTONS,

	EV_ENTER_TEXT_MODE,
	EV_LEAVE_TEXT_MODE,

	EV_PROTRACTOR_EVENT,
	EV_MECH_MESSIAH_EVENT,

	EV_GET_BLOCK_PHRASE,

	EV_PAUSE_AML,
	EV_RESUME_AML,

	EV_ENTER_CHAT,
	EV_LEAVE_CHAT,

	EV_ITEM_TEXT,

	EV_GET_RUBOX,
	EV_INIT_AVI_OBJECT,

	EV_VSS_CAMERA_ROT_EVENT,
	EV_VSS_CAMERA_ZOOM_EVENT,
	EV_VSS_CAMERA_PERSP_EVENT,

	// item manage events: data is ID of first item, and the ptr is can be the second ID
	EV_VSS_PUT_ITEM_XY,
	EV_VSS_CHANGE_ITEMS,
	EV_VSS_SET_MOVE_ITEM,

	EV_MAX_CODE
};

#endif