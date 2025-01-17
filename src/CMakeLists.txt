include_directories(
	"${PROJECT_SOURCE_DIR}/lib/renderer/src"
	"${PROJECT_SOURCE_DIR}/lib/xtool"
	"${PROJECT_SOURCE_DIR}/lib/xgraph"
	"${PROJECT_SOURCE_DIR}/src/vss/duktape-2.7.0"
)

IF(FFMPEG)
	include_directories("${PROJECT_SOURCE_DIR}/lib/xsound")
ELSE()
	include_directories(
		"${PROJECT_SOURCE_DIR}/overrides/ffmpeg"
		"${PROJECT_SOURCE_DIR}/lib/xsound"
	)
ENDIF()

SET(vangers_SRCS
	3d/3d_math.cpp
	3d/3dgraph.cpp
	3d/3dobject.cpp
	3d/dynamics.cpp
	3d/optimize.cpp
	actint/aci_scr.cpp
	actint/actint.cpp
	actint/actintml.cpp
	actint/ascr_fnc.cpp
	actint/ascript.cpp
	actint/chtree.cpp
	actint/sscript.cpp
	backg.cpp
	dast/poly3d.cpp
	iscreen/controls.cpp
	iscreen/hfont.cpp
	iscreen/i_chat.cpp
	iscreen/iextern.cpp
	iscreen/ikeys.cpp
	iscreen/imap_fnc.cpp
	iscreen/iml.cpp
	iscreen/iscr_fnc.cpp
	iscreen/iscreen.cpp
	iscreen/iscript.cpp
	iscreen/ivmap.cpp
	iscreen/script.cpp
	iscreen/smooth.cpp
	network.cpp
	palette.cpp
	particle/bmp2scr.cpp
	particle/deform.cpp
	particle/df.cpp
	particle/light.cpp
	particle/particle.cpp
	particle/partmap.cpp
	particle/pmaptype.cpp
	rle.cpp
	road.cpp
	sound/music.cpp
	sound/sound.cpp
	#sqint/sqibody.cpp #FOR surmap
	#sqint/sqicore.cpp #FOR surmap
	terra/compress.cpp
	terra/huff1.cpp
	terra/land.cpp
	terra/perpslop.cpp
	terra/siderend.cpp #ASM
	terra/slopskip.cpp
	terra/splay.cpp
	terra/vmap.cpp #ASM
	units/effect.cpp
	units/hobj.cpp
	units/items.cpp
	units/mechos.cpp
	units/moveland.cpp
	units/sensor.cpp
	units/track.cpp
	uvs/diagen.cpp
	uvs/screen.cpp
	uvs/univang.cpp
	xjoystick.cpp
	xsocket.cpp
	zmod_client.cpp
	${WINDOWS_RES}
	actint/layout.h
	WDisp.cpp
)

SET(vss_SRCS
		vss/sys.cpp
		vss/sys-modules.cpp
		vss/sys-bridge.cpp
		vss/sys-quant.cpp
		vss/sys-experimental.cpp
		vss/duktape-2.7.0/duktape.c
		vss/duktape-2.7.0/extras/console/duk_console.c
		vss/duktape-2.7.0/extras/module-node/duk_module_node.c vss/sys-experimental.cpp)

if (ANDROID)
	ADD_LIBRARY(vangers STATIC ${vangers_SRCS} ${vss_SRCS}
		$<TARGET_OBJECTS:xtool>
		$<TARGET_OBJECTS:xgraph>
		$<TARGET_OBJECTS:xsound>
		$<TARGET_OBJECTS:renderer>
		$<TARGET_OBJECTS:glad>
	)
else()
	ADD_EXECUTABLE(vss ${vangers_SRCS} ${vss_SRCS}
		$<TARGET_OBJECTS:xtool>
		$<TARGET_OBJECTS:xgraph>
		$<TARGET_OBJECTS:xsound>
	)

	IF(WIN32)
		SET(WIN_LIB
			wsock32
   			dbghelp
			#-mwindows
			#-Wl,-subsystem,windows
		)
	ENDIF(WIN32)

	TARGET_LINK_LIBRARIES(vss
		${SDL2_LIBRARY}
		${OGG_LIBRARY}
		${VORBIS_LIBRARY}
		${VORBISFILE_LIBRARY}
		${CLUNK_LIBRARY}
		${SDL2_NET_LIBRARY}
		${FFMPEG_LIBRARIES}
		${ZLIB_LIBRARIES}
		${OPENGL_LIBRARIES}
		${WIN_LIB}
		${STEAM_LIBS}
		renderer
		xtool
		xgraph
		xsound
	)
endif(ANDROID)
