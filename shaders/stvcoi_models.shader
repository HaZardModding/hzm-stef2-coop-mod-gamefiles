///////////////////////////////////////////////////////////
//////////////////////////DEFIANT//////////////////////////
///////////////////////////////////////////////////////////
/////////////By Explorer and 7o'nine for STVCOI mod////////

defstool_1
{
	qer_editorimage models/enviro/defiant/bridge/defstool_1
	nopicmip
	nomipmaps
	{
		map models/sky/UI-ent-dome/env_diffused.tga
		detail
		rgbGen default
		tcGen environment
		tcMod scale .8 .8 
	}
	{
		map models/enviro/defiant/bridge/defstool_1.tga
		blendFunc blend
		rgbGen default
	}
}


models/enviro/defiant/bridge/defmedkit_1
{
    {
        map models/enviro/defiant/bridge/defmedkit_1.tga
        blendFunc GL_ONE GL_ZERO
	rgbGen vertex
    }
    {
        map models/enviro/defiant/bridge/shine2.tga
        //blendFunc GL_DST_COLOR GL_SRC_COLOR
	blendFunc GL_DST_COLOR GL_DST_COLOR
        detail
        rgbGen identity
        tcGen environment
    }
}

///////////////////////////////////////////////////////////
//////////////////////////VOYAGER//////////////////////////
///////////////////////////////////////////////////////////

//////////////////////////////////////
//
//       laptop01
//
//////////////////////////////////////
models/enviro/voyager/electronics/laptop01
{
	qer_editorimage models/enviro/voyager/electronics/laptop01.tga
	surfaceparm nomarks
	{
		map $lightmap 
		rgbGen identity
		tcGen lightmap 
	}
	{
		map models/enviro/voyager/electronics/laptop01.tga
		blendfunc filter
		rgbGen identity
	}
	{
		map models/enviro/voyager/electronics/laptop01a.tga
		blendfunc add
		rgbGen wave sin 0.95 0.1 0 1 
	}
}

//////////////////////////////////////
//
//       padd01
//
//////////////////////////////////////
models/enviro/voyager/electronics/padd01
{
	qer_editorimage models/enviro/voyager/electronics/padd01.tga
	surfaceparm nomarks
	{
		map $lightmap 
		rgbGen identity
		tcGen lightmap 
	}
	{
		map models/enviro/voyager/electronics/padd01.tga
		blendfunc filter
		rgbGen identity
	}
	{
		map models/enviro/voyager/electronics/padd01a.tga
		blendfunc add
		rgbGen wave sin 0.95 0.1 0 1 
	}
}

//////////////////////////////////////
//
//       padd02
//
//////////////////////////////////////
models/enviro/voyager/electronics/padd02
{
	qer_editorimage models/enviro/voyager/electronics/padd02.tga
	surfaceparm nomarks
	{
		map $lightmap 
		rgbGen identity
		tcGen lightmap 
	}
	{
		map models/enviro/voyager/electronics/padd02.tga
		blendfunc filter
		rgbGen identity
	}
	{
		map models/enviro/voyager/electronics/padd02a.tga
		blendfunc add
		rgbGen wave sin 0.95 0.1 0 1 
	}
}


///////////////////////TURBOLIFT/////////////////////

models/enviro/voyager/turbo/wallflasher
{
	qer_editorimage models/enviro/voyager/turbo/wallflash.tga
	surfaceparm nomarks
	{
		map $lightmap 
		rgbGen identity
		tcGen lightmap 
	}
	{
		map models/enviro/voyager/turbo/wallflash.tga
		blendfunc filter
		rgbGen identity
	}
	{
		map models/enviro/voyager/turbo/wallflasha.tga
		blendfunc add
		rgbGen wave sin 0.95 0.1 0 1 
	}
}


models/enviro/voyager/turbo/wallplain
{
	qer_editorimage models/enviro/voyager/turbo/wallplain.tga
	surfaceparm nomarks
	{
		map $lightmap 
		rgbGen identity
		tcGen lightmap 
	}
	{
		map models/enviro/voyager/turbo/wallplain.tga
		blendfunc filter
		rgbGen identity
	}
	{
		map models/enviro/voyager/turbo/wallplaina.tga
		blendfunc add
		rgbGen wave sin 0.95 0.1 0 1 
	}
}

models/enviro/voyager/turbo/wallsides
{
	qer_editorimage models/enviro/voyager/turbo/wallsides.tga
	surfaceparm nomarks
	{
		map $lightmap 
		rgbGen identity
		tcGen lightmap 
	}
	{
		map models/enviro/voyager/turbo/wallsides.tga
		blendfunc filter
		rgbGen identity
	}
	{
		map models/enviro/voyager/turbo/wallsidesa.tga
		blendfunc add
		rgbGen wave sin 0.95 0.1 0 1 
	}
}

models/enviro/voyager/turbo/turbo
{
	qer_editorimage models/enviro/voyager/turbo/turbo.tga
	surfaceparm nomarks
	{
		map $lightmap 
		rgbGen identity
		tcGen lightmap 
	}
	{
		map models/enviro/voyager/turbo/turbo.tga
		blendfunc filter
		rgbGen identity
	}
	{
		map models/enviro/voyager/turbo/turboa.tga
		blendfunc add
		rgbGen wave sin 0.95 0.1 0 1 
	}
}

//When turbo is moving
models/enviro/voyager/turbo/wallflasher2
{
	qer_editorimage models/enviro/voyager/turbo/wallflash.tga
	{
		map models/enviro/voyager/turbo/wallflash2.tga
		tcMod scroll 0 0.75
	}
	{
		map models/enviro/voyager/turbo/wallflash.tga
		blendfunc blend
	}
}

models/enviro/voyager/turbo/panels
{
	qer_editorimage models/enviro/voyager/turbo/panel.tga
	{
		map models/enviro/voyager/turbo/panel.tga
		blendfunc blend
	}
}

