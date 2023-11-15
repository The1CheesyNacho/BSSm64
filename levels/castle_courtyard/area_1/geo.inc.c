#include "src/game/envfx_snow.h"

const GeoLayout castle_courtyard_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_courtyard_dl_castle_courtyard_seg7_dl_070048B8_mesh_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, castle_courtyard_dl_castle_courtyard_seg7_dl_070048B8_mesh_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_ALPHA, castle_courtyard_dl_castle_courtyard_seg7_dl_070048B8_mesh_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout castle_courtyard_area_1[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(0),
		GEO_OPEN_NODE(),
			GEO_NODE_ORTHO(100.0000),
			GEO_OPEN_NODE(),
				GEO_BACKGROUND(BACKGROUND_OCEAN_SKY, geo_skybox_main),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
            GEO_CAMERA_FRUSTUM_WITH_FUNC(45, 100, 12800, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(16, 0, 2000, 6000, 0, 0, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, castle_courtyard_area_1_geo),
					GEO_RENDER_OBJ(),
                    GEO_ASM(   0, geo_movtex_pause_control),
                    GEO_ASM(0x2601, geo_movtex_draw_water_regions),
                    GEO_ASM(0, geo_envfx_main),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_courtyard_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, castle_courtyard_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, castle_courtyard_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
