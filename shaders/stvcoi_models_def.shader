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
