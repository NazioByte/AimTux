#include "hvh_panel.h"

HVHPanel::HVHPanel (Vector2D position, Vector2D size)
	: Panel::Panel (position, size)
{
	
	ba_antiaim = new Banner ("AntiAim", LOC (10, 10), (size.x - 20) / 2 - 5);
	AddComponent (ba_antiaim);
	
	ts_antiaim_x = new ToggleSwitch ("x axis", BELOW (ba_antiaim), 33, &Settings::AntiAim::enabled_X);
	AddComponent (ts_antiaim_x);
	
	
	lb_antiaim_x = new ListBox<AntiAimType_X> ("anti aim type", BELOW (ts_antiaim_x), 170, &Settings::AntiAim::type_X, std::vector<LB_Element>
		{
			LB_Element ("UP", STATIC_UP),
			LB_Element ("DOWN", STATIC_DOWN)
		}
	);
	AddComponent (lb_antiaim_x);
	
	
	ts_antiaim_y = new ToggleSwitch ("y axis", BELOW (lb_antiaim_x), 33, &Settings::AntiAim::enabled_Y);
	AddComponent (ts_antiaim_y);
	
	lb_antiaim_y = new ListBox<AntiAimType_Y> ("anti aim type", BELOW (ts_antiaim_y), 170, &Settings::AntiAim::type_Y, std::vector<LB_Element>
		{
			LB_Element ("SLOW SPIN", SPIN_SLOW),
			LB_Element ("FAST SPIN", SPIN_FAST),
			LB_Element ("JITTER", JITTER),
			LB_Element ("SIDE", SIDE),
			LB_Element ("BACKWARDS", BACKWARDS),
			LB_Element ("FAKE4", FAKE4),
#ifdef UNTRUSTED_SETTINGS
			LB_Element ("LISP", LISP)
#endif
		}
	);
	AddComponent (lb_antiaim_y);
	
	
	ba_autowall = new Banner ("AutoWall", STACK (ba_antiaim), (size.x - 20) / 2 - 5);
	AddComponent (ba_autowall);

	lb_bone_select_multi = new MS_ListBox<Hitbox> ("Autowall bones", BELOW (ba_autowall), 170, &Settings::Aimbot::AutoWall::bones, std::vector<LB_Element>
		{
			LB_Element ("HEAD", HITBOX_HEAD),
			LB_Element ("NECK", HITBOX_NECK),
			LB_Element ("PELVIS", HITBOX_PELVIS),
			LB_Element ("SPINE", HITBOX_SPINE),
			LB_Element ("LEGS", HITBOX_LEGS),
			LB_Element ("ARMS", HITBOX_ARMS)
		}
	);
	AddComponent (lb_bone_select_multi);
	
	Hide ();
}
