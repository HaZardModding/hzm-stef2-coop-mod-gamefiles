//////////////////////////////////////
//Defiant Bridge Ceiling 01
//Made/Edited by Explorer
//explorer-studios@mail.com
//
//////////////////////////////////////
//
textures/def_fx/df_warp01
{
	qer_editorimage textures/def_fx/df_warp01.tga
	surfaceparm nonsolid
	surfaceparm playerclip
	surfaceparm trans
	surfaceparm monsterclip
	cull disable
	nopicmip
	{
		map textures/def_fx/df_warp01.tga
		blendfunc gl_src_alpha gl_dst_alpha
		rgbGen identity
		tcMod scroll 1 0
		depthWrite
		alphaFunc GT0
	}
}

//////////////////////////////////////
//Defiant Bridge Ceiling 01
//Made/Edited by Explorer
//explorer-studios@mail.com
//
//////////////////////////////////////
//
textures/def_fx/df_warp02
{
	qer_editorimage textures/def_fx/df_warp02.tga
	surfaceparm nonsolid
	surfaceparm playerclip
	surfaceparm trans
	surfaceparm monsterclip
	cull disable
	nopicmip
	{
		map textures/def_fx/df_warp02.tga
		blendfunc gl_src_alpha gl_dst_alpha
		rgbGen identity
		tcMod scroll 1 0
		depthWrite
		alphaFunc GT0
	}
}

//////////////////////////////////////
//Defiant Hall Lcars 04
//Made/Edited by Explorer
//explorer@exp-ind.com
//
//////////////////////////////////////
//
textures/def_fx/df_space01
{
	qer_editorimage textures/def_fx/df_space01.tga
	surfaceparm nomarks
	{
		map $lightmap 
		rgbGen identity
		tcGen lightmap 
	}
	{
		map textures/def_fx/df_fog01.tga
		blendfunc filter
		rgbGen identity
	}
	{
		map textures/def_fx/df_space01.tga
		blendfunc add
		rgbGen identity
		tcGen environment 
	}
}

//////////////////////////////////////
//Defiant Bridge Ceiling 01
//Made/Edited by Explorer
//explorer-studios@mail.com
//
//////////////////////////////////////
//
textures/def_fx/df_warp03
{
	qer_editorimage textures/def_fx/df_warp03.tga
	surfaceparm nonsolid
	surfaceparm playerclip
	surfaceparm trans
	surfaceparm monsterclip
	cull disable
	nopicmip
	{
		map textures/def_fx/df_warp03.tga
		blendfunc gl_src_alpha gl_dst_alpha
		rgbGen identity
		tcMod scroll 1 0
		depthWrite
		alphaFunc GT0
	}
}

//////////////////////////////////////
//Defiant Hall Circuit 04
//Made/Edited by Explorer
//explorer@exp-ind.com
//
//////////////////////////////////////
//
textures/def_fx/df_light01
{
	qer_editorimage textures/def_fx/df_light01.tga
	surfaceparm nomarks
	{
		map $lightmap 
		rgbGen identity
		tcGen lightmap 
	}
	{
		map textures/def_fx/df_light01.tga
		blendfunc filter
		rgbGen identity
	}
	{
		map textures/def_fx/df_light01a.tga
		blendfunc add
		rgbGen wave sin 0.7 0.1 0 0.4 
	}
}

