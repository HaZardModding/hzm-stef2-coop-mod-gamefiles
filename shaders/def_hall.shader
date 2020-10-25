//////////////////////////////////////
//Defiant Hall Light 01
//Made/Edited by Explorer
//explorer@exp-ind.com
//
//////////////////////////////////////
//
textures/def_hall/dh_light01
{
	qer_editorimage textures/def_hall/dh_light01.tga
	surfaceparm nomarks
	{
		map $lightmap 
		rgbGen identity
		tcGen lightmap 
	}
	{
		map textures/def_hall/dh_light01.tga
		blendfunc filter
		rgbGen identity
	}
	{
		map textures/def_hall/dh_light01a.tga
		blendfunc add
		rgbGen identity
	}
}

//////////////////////////////////////
//Defiant Hall Light 02
//Made/Edited by Explorer
//explorer@exp-ind.com
//
//////////////////////////////////////
//
textures/def_hall/dh_light02
{
	qer_editorimage textures/def_hall/dh_light02.tga
	surfaceparm nomarks
	{
		map $lightmap 
		rgbGen identity
		tcGen lightmap 
	}
	{
		map textures/def_hall/dh_light02.tga
		blendfunc filter
		rgbGen identity
	}
	{
		map textures/def_hall/dh_light02a.tga
		blendfunc add
		rgbGen identity
	}
}

//////////////////////////////////////
//Defiant Hall Light 03
//Made/Edited by Explorer
//explorer@exp-ind.com
//
//////////////////////////////////////
//
textures/def_hall/dh_light03
{
	qer_editorimage textures/def_hall/dh_light03.tga
	surfaceparm nomarks
	{
		map $lightmap 
		rgbGen identity
		tcGen lightmap 
	}
	{
		map textures/def_hall/dh_light03.tga
		blendfunc filter
		rgbGen identity
	}
	{
		map textures/def_hall/dh_light03a.tga
		blendfunc add
		rgbGen identity
	}
}

//////////////////////////////////////
//Defiant Hall Light 04
//Made/Edited by Explorer
//explorer@exp-ind.com
//
//////////////////////////////////////
//
textures/def_hall/dh_light04
{
	qer_editorimage textures/def_hall/dh_light04.tga
	surfaceparm nonsolid
	surfaceparm playerclip
	surfaceparm trans
	surfaceparm monsterclip
	cull disable
	nopicmip
	{
		map textures/def_hall/dh_light04.tga
		blendfunc blend
		rgbGen identity
		depthWrite
		alphaFunc GT0
	}
}

//////////////////////////////////////
//Defiant Hall Lcars 01
//Made/Edited by Explorer
//explorer@exp-ind.com
//
//////////////////////////////////////
textures/def_hall/dh_lcars01
{
	qer_editorimage textures/def_hall/dh_lcars01.tga
	surfaceparm playerclip
	surfaceparm trans
	surfaceparm monsterclip
	cull disable
	nopicmip
	{
		map textures/def_hall/dh_lcars01.tga
		blendfunc blend
		rgbGen identity
		depthWrite
		alphaFunc GT0
	}
	{
		map $lightmap 
		blendfunc filter
		rgbGen identity
		tcGen lightmap 
		depthFunc equal
	}
}

//////////////////////////////////////
//Defiant Hall Lcars 02
//Made/Edited by Explorer
//explorer@exp-ind.com
//
//////////////////////////////////////
textures/def_hall/dh_lcars02
{
	qer_editorimage textures/def_hall/dh_lcars02.tga
	surfaceparm playerclip
	surfaceparm trans
	surfaceparm monsterclip
	cull disable
	nopicmip
	{
		map textures/def_hall/dh_lcars02.tga
		blendfunc blend
		rgbGen identity
		depthWrite
		alphaFunc GT0
	}
	{
		map $lightmap 
		blendfunc filter
		rgbGen identity
		tcGen lightmap 
		depthFunc equal
	}
}

//////////////////////////////////////
//Defiant Hall Light 05
//Made/Edited by Explorer
//explorer@exp-ind.com
//
//////////////////////////////////////
//
textures/def_hall/dh_light05
{
	qer_editorimage textures/def_hall/dh_light05.tga
	surfaceparm nomarks
	{
		map $lightmap 
		rgbGen identity
		tcGen lightmap 
	}
	{
		map textures/def_hall/dh_light05.tga
		blendfunc filter
		rgbGen identity
	}
	{
		map textures/tex_fx/tf_glare01.tga
		blendfunc filter
		rgbGen identity
		tcGen environment 
	}
}

//////////////////////////////////////
//Defiant Hall Lcars 01
//Made/Edited by Explorer
//explorer@exp-ind.com
//
//////////////////////////////////////
textures/def_hall/dh_floor01
{
	qer_editorimage textures/def_hall/dh_floor01.tga
	surfaceparm playerclip
	surfaceparm trans
	surfaceparm monsterclip
	cull disable
	nopicmip
	{
		map textures/def_hall/dh_floor01.tga
		blendfunc blend
		rgbGen identity
		depthWrite
		alphaFunc GT0
	}
	{
		map textures/tex_fx/tf_glare01.tga
		blendfunc filter
		rgbGen identity
		tcGen environment 
	}
	{
		map $lightmap 
		blendfunc filter
		rgbGen identity
		tcGen lightmap 
		depthFunc equal
	}
}

//////////////////////////////////////
//Defiant Hall Light 07
//Made/Edited by Explorer
//explorer@exp-ind.com
//
//////////////////////////////////////
//
textures/def_hall/dh_light07
{
	qer_editorimage textures/def_hall/dh_light07.tga
	surfaceparm nomarks
	{
		map $lightmap 
		rgbGen identity
		tcGen lightmap 
	}
	{
		map textures/tex_fx/tf_glare01.tga
		blendfunc filter
		rgbGen identity
		tcGen environment 
	}
	{
		map textures/def_hall/dh_light07.tga
		blendfunc gl_one gl_one_minus_dst_color
		rgbGen identity
	}
}

//////////////////////////////////////
//Defiant Hall Circuits 01
//Made/Edited by Explorer
//explorer@exp-ind.com
//
//////////////////////////////////////
//
textures/def_hall/dh_circuits01
{
	qer_editorimage textures/def_hall/dh_circuits01.tga
	surfaceparm nonsolid
	surfaceparm playerclip
	surfaceparm trans
	surfaceparm monsterclip
	cull disable
	nopicmip
	{
		map textures/def_hall/dh_circuits01.tga
		blendfunc blend
		rgbGen wave sin 0.99 0.1 0 1 
		depthWrite
		alphaFunc GT0
	}
}

//////////////////////////////////////
//Defiant Hall Pipe 01
//Made/Edited by Explorer
//explorer@exp-ind.com
//
//////////////////////////////////////
//
textures/def_hall/dh_pipe01
{
	qer_editorimage textures/def_hall/dh_pipe01.tga
	{
		map textures/tex_fx/tf_glare02.tga
		rgbGen identity
		tcGen environment 
	}
	{
		map textures/def_hall/dh_pipe01.tga
		blendfunc gl_src_color gl_src_color
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc filter
		tcGen lightmap 
	}
}

//////////////////////////////////////
//Defiant Hall Pipe 02
//Made/Edited by Explorer
//explorer@exp-ind.com
//
//////////////////////////////////////
//
textures/def_hall/dh_pipe02
{
	qer_editorimage textures/def_hall/dh_pipe02.tga
	{
		map textures/tex_fx/tf_glare02.tga
		rgbGen identity
		tcGen environment 
	}
	{
		map textures/def_hall/dh_pipe02.tga
		blendfunc gl_src_color gl_src_color
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc filter
		tcGen lightmap 
	}
}

//////////////////////////////////////
//Defiant Hall Pipe 03
//Made/Edited by Explorer
//explorer@exp-ind.com
//
//////////////////////////////////////
//
textures/def_hall/dh_pipe03
{
	qer_editorimage textures/def_hall/dh_pipe03.tga
	{
		map textures/tex_fx/tf_glare02.tga
		rgbGen identity
		tcGen environment 
	}
	{
		map textures/def_hall/dh_pipe03.tga
		blendfunc gl_src_color gl_src_color
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc filter
		tcGen lightmap 
	}
}

//////////////////////////////////////
//Defiant Hall Pipe 04
//Made/Edited by Explorer
//explorer@exp-ind.com
//
//////////////////////////////////////
//
textures/def_hall/dh_pipe04
{
	qer_editorimage textures/def_hall/dh_pipe04.tga
	{
		map textures/tex_fx/tf_glare02.tga
		rgbGen identity
		tcGen environment 
	}
	{
		map textures/def_hall/dh_pipe04.tga
		blendfunc gl_src_color gl_src_color
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc filter
		tcGen lightmap 
	}
}

//////////////////////////////////////
//Defiant Hall Pipe 05
//Made/Edited by Explorer
//explorer@exp-ind.com
//
//////////////////////////////////////
//
textures/def_hall/dh_pipe05
{
	qer_editorimage textures/def_hall/dh_pipe05.tga
	{
		map textures/tex_fx/tf_glare02.tga
		rgbGen identity
		tcGen environment 
	}
	{
		map textures/def_hall/dh_pipe05.tga
		blendfunc gl_src_color gl_src_color
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc filter
		tcGen lightmap 
	}
}

//////////////////////////////////////
//Defiant Hall Pipe 06
//Made/Edited by Explorer
//explorer@exp-ind.com
//
//////////////////////////////////////
//
textures/def_hall/dh_pipe06
{
	qer_editorimage textures/def_hall/dh_pipe06.tga
	{
		map textures/tex_fx/tf_glare02.tga
		rgbGen identity
		tcGen environment 
	}
	{
		map textures/def_hall/dh_pipe06.tga
		blendfunc gl_src_color gl_src_color
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc filter
		tcGen lightmap 
	}
}

//////////////////////////////////////
//Defiant Hall Pipe 07
//Made/Edited by Explorer
//explorer@exp-ind.com
//
//////////////////////////////////////
//
textures/def_hall/dh_pipe07
{
	qer_editorimage textures/def_hall/dh_pipe07.tga
	{
		map textures/tex_fx/tf_glare02.tga
		rgbGen identity
		tcGen environment 
	}
	{
		map textures/def_hall/dh_pipe07.tga
		blendfunc gl_src_color gl_src_color
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc filter
		tcGen lightmap 
	}
}

//////////////////////////////////////
//Defiant Hall Pipe 09
//Made/Edited by Explorer
//explorer@exp-ind.com
//
//////////////////////////////////////
//
textures/def_hall/dh_pipe09
{
	qer_editorimage textures/def_hall/dh_pipe09.tga
	{
		map textures/tex_fx/tf_glare02.tga
		rgbGen identity
		tcGen environment 
	}
	{
		map textures/def_hall/dh_pipe09.tga
		blendfunc gl_src_color gl_src_color
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc filter
		tcGen lightmap 
	}
}

//////////////////////////////////////
//Defiant Hall Light 09
//Made/Edited by Explorer
//explorer@exp-ind.com
//
//////////////////////////////////////
//
textures/def_hall/dh_light09
{
	qer_editorimage textures/def_hall/dh_light09.tga
	surfaceparm nomarks
	{
		map $lightmap 
		rgbGen identity
		tcGen lightmap 
	}
	{
		map textures/def_hall/dh_light09.tga
		blendfunc filter
		rgbGen identity
	}
	{
		map textures/def_hall/dh_light09a.tga
		blendfunc add
		rgbGen identity
	}
}

//////////////////////////////////////
//Defiant Hall Floor 02
//Made/Edited by Explorer
//explorer@exp-ind.com
//
//////////////////////////////////////
textures/def_hall/dh_floor02
{
	qer_editorimage textures/def_hall/dh_floor02.tga
	surfaceparm playerclip
	surfaceparm trans
	surfaceparm monsterclip
	cull disable
	nopicmip
	{
		map textures/def_hall/dh_floor02.tga
		blendfunc blend
		rgbGen identity
		depthWrite
		alphaFunc GT0
	}
	{
		map textures/tex_fx/tf_glare02.tga
		blendfunc filter
		rgbGen identity
		tcGen environment 
	}
	{
		map $lightmap 
		blendfunc filter
		rgbGen identity
		tcGen lightmap 
		depthFunc equal
	}
}

//////////////////////////////////////
//Defiant Hall Warp 01
//Made/Edited by Explorer
//explorer@exp-ind.com
//
//////////////////////////////////////
//
textures/def_hall/dh_warp01
{
	qer_editorimage textures/def_hall/dh_warp01.tga
	surfaceparm nomarks
	{
		map $lightmap 
		rgbGen identity
		tcGen lightmap 
	}
	{
		map textures/def_hall/dh_warp01.tga
		blendfunc filter
		rgbGen identity
	}
	{
		map textures/def_hall/dh_warp01a.tga
		blendfunc add
		rgbGen identity
	}
}

//////////////////////////////////////
//Defiant Hall Wires 01
//Made/Edited by Explorer
//explorer@exp-ind.com
//
//////////////////////////////////////
//
textures/def_hall/dh_wires01
{
	qer_editorimage textures/def_hall/dh_wires01.tga
	{
		map textures/tex_fx/tf_glare01.tga
		rgbGen identity
		tcGen environment 
	}
	{
		map textures/def_hall/dh_wires01.tga
		blendfunc gl_src_color gl_src_color
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc filter
		tcGen lightmap 
	}
}

//////////////////////////////////////
//Defiant Hall Wires 02
//Made/Edited by Explorer
//explorer@exp-ind.com
//
//////////////////////////////////////
//
textures/def_hall/dh_wires02
{
	qer_editorimage textures/def_hall/dh_wires02.tga
	{
		map textures/tex_fx/tf_glare01.tga
		rgbGen identity
		tcGen environment 
	}
	{
		map textures/def_hall/dh_wires02.tga
		blendfunc gl_src_color gl_src_color
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc filter
		tcGen lightmap 
	}
}

//////////////////////////////////////
//Defiant Hall Wires 03
//Made/Edited by Explorer
//explorer@exp-ind.com
//
//////////////////////////////////////
//
textures/def_hall/dh_wires03
{
	qer_editorimage textures/def_hall/dh_wires03.tga
	{
		map textures/tex_fx/tf_glare01.tga
		rgbGen identity
		tcGen environment 
	}
	{
		map textures/def_hall/dh_wires03.tga
		blendfunc gl_src_color gl_src_color
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc filter
		tcGen lightmap 
	}
}

//////////////////////////////////////
//Defiant Hall Wires 04
//Made/Edited by Explorer
//explorer@exp-ind.com
//
//////////////////////////////////////
//
textures/def_hall/dh_wires04
{
	qer_editorimage textures/def_hall/dh_wires04.tga
	{
		map textures/tex_fx/tf_glare01.tga
		rgbGen identity
		tcGen environment 
	}
	{
		map textures/def_hall/dh_wires04.tga
		blendfunc gl_src_color gl_src_color
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc filter
		tcGen lightmap 
	}
}

//////////////////////////////////////
//Defiant Hall Circuit 02
//Made/Edited by Explorer
//explorer@exp-ind.com
//
//////////////////////////////////////
//
textures/def_hall/dh_circuits02
{
	qer_editorimage textures/def_hall/dh_circuits02.tga
	surfaceparm nomarks
	{
		map $lightmap 
		rgbGen identity
		tcGen lightmap 
	}
	{
		map textures/def_hall/dh_circuits02.tga
		blendfunc filter
		rgbGen identity
	}
	{
		map textures/def_hall/dh_circuits02a.tga
		blendfunc add
		rgbGen wave sin 0.7 0.1 0 0.4 
	}
}

//////////////////////////////////////
//Defiant Hall Wall 14
//Made/Edited by Explorer
//explorer@exp-ind.com
//
//////////////////////////////////////
//
textures/def_hall/dh_wall14
{
	qer_editorimage textures/def_hall/dh_wall14.tga
	{
		map textures/tex_fx/tf_glare02.tga
		rgbGen identity
		tcGen environment 
	}
	{
		map textures/def_hall/dh_wall14.tga
		blendfunc gl_src_color gl_src_color
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc filter
		tcGen lightmap 
	}
}

//////////////////////////////////////
//Defiant Hall Wall 15
//Made/Edited by Explorer
//explorer@exp-ind.com
//
//////////////////////////////////////
//
textures/def_hall/dh_wall15
{
	qer_editorimage textures/def_hall/dh_wall15.tga
	{
		map textures/tex_fx/tf_glare02.tga
		rgbGen identity
		tcGen environment 
	}
	{
		map textures/def_hall/dh_wall15.tga
		blendfunc gl_src_color gl_src_color
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc filter
		tcGen lightmap 
	}
}

//////////////////////////////////////
//Defiant Hall Wall 16
//Made/Edited by Explorer
//explorer@exp-ind.com
//
//////////////////////////////////////
//
textures/def_hall/dh_wall16
{
	qer_editorimage textures/def_hall/dh_wall14.tga
	{
		map textures/tex_fx/tf_glare02.tga
		rgbGen identity
		tcGen environment 
	}
	{
		map textures/def_hall/dh_wall16.tga
		blendfunc gl_src_color gl_src_color
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc filter
		tcGen lightmap 
	}
}

//////////////////////////////////////
//Defiant Hall Circuit 03
//Made/Edited by Explorer
//explorer@exp-ind.com
//
//////////////////////////////////////
//
textures/def_hall/dh_circuits03
{
	qer_editorimage textures/def_hall/dh_circuits03.tga
	surfaceparm nomarks
	{
		map $lightmap 
		rgbGen identity
		tcGen lightmap 
	}
	{
		map textures/def_hall/dh_circuits03.tga
		blendfunc filter
		rgbGen identity
	}
	{
		map textures/def_hall/dh_circuits03a.tga
		blendfunc add
		rgbGen wave sin 0.7 0.1 0 0.4 
	}
}

//////////////////////////////////////
//Defiant Hall Circuit 04
//Made/Edited by Explorer
//explorer@exp-ind.com
//
//////////////////////////////////////
//
textures/def_hall/dh_circuits04
{
	qer_editorimage textures/def_hall/dh_circuits04.tga
	surfaceparm nomarks
	{
		map $lightmap 
		rgbGen identity
		tcGen lightmap 
	}
	{
		map textures/def_hall/dh_circuits04.tga
		blendfunc filter
		rgbGen identity
	}
	{
		map textures/def_hall/dh_circuits04a.tga
		blendfunc add
		rgbGen wave sin 0.7 0.1 0 0.4 
	}
}

//////////////////////////////////////
//Defiant Hall Warp 02
//Made/Edited by Explorer
//explorer@exp-ind.com
//
//////////////////////////////////////
//
textures/def_hall/dh_warp02
{
	qer_editorimage textures/def_hall/dh_warp02.tga
	surfaceparm nomarks
	{
		map $lightmap 
		rgbGen identity
		tcGen lightmap 
	}
	{
		map textures/def_hall/dh_warp02.tga
		blendfunc filter
		rgbGen identity
	}
	{
		map textures/def_hall/dh_warp02a.tga
		blendfunc add
		rgbGen identity
		tcMod scroll -0.8 0
	}
}

//////////////////////////////////////
//Defiant Hall Lcars 04
//Made/Edited by Explorer
//explorer@exp-ind.com
//
//////////////////////////////////////
//
textures/def_hall/dh_lcars04
{
	qer_editorimage textures/def_hall/dh_lcars04.tga
	surfaceparm nomarks
	{
		map $lightmap 
		rgbGen identity
		tcGen lightmap 
	}
	{
		map textures/def_hall/dh_lcars04.tga
		blendfunc filter
		rgbGen identity
	}
	{
		map textures/def_hall/dh_lcars04a.tga
		blendfunc add
		rgbGen identity
	}
}

//////////////////////////////////////
//Defiant Hall Lcars 04
//Made/Edited by Explorer
//explorer@exp-ind.com
//
//////////////////////////////////////
//
textures/def_hall/dh_turbo07
{
	qer_editorimage textures/def_hall/dh_turbo07.tga
	surfaceparm nomarks
	{
		map $lightmap 
		rgbGen identity
		tcGen lightmap 
	}
	{
		map textures/def_hall/dh_turbo07.tga
		blendfunc filter
		rgbGen identity
	}
	{
		map textures/def_hall/dh_turbo07a.tga
		blendfunc add
		rgbGen wave sin 0.95 0.01 0 1 
	}
}

//////////////////////////////////////
//Defiant Hall Lcars 04
//Made/Edited by Explorer
//explorer@exp-ind.com
//
//////////////////////////////////////
//
textures/def_hall/dh_turbo09
{
	qer_editorimage textures/def_hall/dh_turbo09.tga
	surfaceparm nomarks
	{
		map $lightmap 
		rgbGen identity
		tcGen lightmap 
	}
	{
		map textures/def_hall/dh_turbo09.tga
		blendfunc filter
		rgbGen identity
	}
	{
		map textures/def_hall/dh_turbo09a.tga
		blendfunc add
		rgbGen wave sin 0.95 0.01 0 1 
	}
}

//////////////////////////////////////
//Defiant Hall Lcars 01
//Made/Edited by Explorer
//explorer@exp-ind.com
//
//////////////////////////////////////
textures/def_hall/dh_lcars05
{
	qer_editorimage textures/def_hall/dh_lcars05.tga
	surfaceparm playerclip
	surfaceparm trans
	surfaceparm monsterclip
	cull disable
	nopicmip
	{
		map textures/def_hall/dh_lcars05.tga
		blendfunc blend
		rgbGen identity
		depthWrite
		alphaFunc GT0
	}
	{
		map $lightmap 
		blendfunc filter
		rgbGen identity
		tcGen lightmap 
		depthFunc equal
	}
}

//////////////////////////////////////
//Defiant Hall Lcars 01
//Made/Edited by Explorer
//explorer@exp-ind.com
//
//////////////////////////////////////
textures/def_hall/dh_lcars06
{
	qer_editorimage textures/def_hall/dh_lcars06.tga
	surfaceparm playerclip
	surfaceparm trans
	surfaceparm monsterclip
	cull disable
	nopicmip
	{
		map textures/def_hall/dh_lcars06.tga
		blendfunc blend
		rgbGen identity
		depthWrite
		alphaFunc GT0
	}
	{
		map $lightmap 
		blendfunc filter
		rgbGen identity
		tcGen lightmap 
		depthFunc equal
	}
}

