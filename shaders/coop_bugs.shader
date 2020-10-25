//Special Texture Properties for the level coop_bugs

textures/coop_bugs/waterfall
{
	surfaceparm nonsolid
	surfaceparm nolightmap
	surfaceparm trans
	surfaceparm water
	tessSize 128
	
	qer_editorimage textures/drull_ruins2_exterior/swampwater1b.tga
	{
		map textures/drull_ruins2_exterior/swampwater1b.tga
		blendfunc blend
		rgbGen identity
		alphagen constant .2
		tcmod scroll .5 0 
		tcMod turb 0.015 0.019 0 0.19
	}  
	{
		map textures/env/env_diffused.tga
		blendFunc blend
		alphagen constant .2
		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA		
		tcGen environment
		rgbgen identity
	}
	{
		map textures/drull_ruins2_exterior/swampwater1b.tga
		blendFunc blend
		tcMod turb 0.015 0.015 0 0.15
		tcmod scroll .05 0.0251
		alphagen constant .3
		rgbGen identity
	}
}

textures/coop_bugs/water-noDeform
{
	surfaceparm nonsolid
	surfaceparm nolightmap
	surfaceparm trans
	surfaceparm water
	tessSize 128

	qer_editorimage textures/drull_ruins2_exterior/swampwater1b.tga
	{
		map textures/drull_ruins2_exterior/swampwater1b.tga
		blendfunc blend
		rgbGen identity
		alphagen constant .2
		tcmod scroll .02 0 
		tcMod turb 0.015 0.019 0 0.19
	}  
	{
		map textures/env/env_diffused.tga
		blendFunc blend
		alphagen constant .2
		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA		
		tcGen environment
		rgbgen identity
	}
	{
		map textures/drull_ruins2_exterior/swampwater1b.tga
		blendFunc blend
		tcMod turb 0.015 0.015 0 0.15
		tcmod scroll .02 0.0251
		alphagen constant .3
		rgbGen identity
	}
}

textures/coop_bugs/idrull-bomb
{
nopicmip
    {
	clampmap textures/coop_bugs/1.tga
	blendfunc BLEND
    }
}

textures/coop_bugs/enhancerArea
{
nopicmip
    {
	clampmap textures/coop_bugs/5.tga
	blendfunc BLEND
    }
}
textures/coop_bugs/enhancer
{
nopicmip
    {
	clampmap textures/coop_bugs/6.tga
	blendfunc BLEND
    }
}

textures/coop_bugs/enhancer-standing
{
   nopicmip
   {
		clampmap textures/coop_bugs/8.tga
		blendfunc BLEND
   }
}

textures/coop_bugs/s0
{
   nomipmaps
   nopicmip
   cull none
   {
		map textures/coop_bugs/8.tga
		blendfunc blend
		alphaFunc GT0
		alphaGen global
		//-,-,mentode,base,amplitude,phase,frequency
		rgbGen wave square 1 1 0.5 0.25
   }
}

coop_bugs-info-bg
{
   nomipmaps
   nopicmip
   cull none
   {
		map sysimg/hud/coop_9.tga
		blendfunc blend
		alphaFunc GT0
		alphaGen global
   }
}

coop_bugs-data-bg
{
   nomipmaps
   nopicmip
   cull none
   {
		map textures/coop_bugs/0.tga
		blendfunc blend
		alphaFunc GT0
		alphaGen global
   }
}

coop_bugs-data-btn-bg
{
   nomipmaps
   nopicmip
   cull none
   {
		map textures/coop_bugs/2.tga
		blendfunc blend
		alphaFunc GT0
		alphaGen global
   }
}

coop_bugs-data2-bg
{
   nomipmaps
   nopicmip
   cull none
   {
		map textures/coop_bugs/3.tga
		blendfunc blend
		alphaFunc GT0
		alphaGen global
   }
}

coop_bugs-data-anim-excelsior-battle
{
   nomipmaps
   nopicmip
   cull none
   {
		animmap 2 textures/coop_bugs/a1a.tga textures/coop_bugs/a1b.tga textures/coop_bugs/a1c.tga textures/coop_bugs/a1d.tga textures/coop_bugs/a1e.tga textures/coop_bugs/a1f.tga textures/coop_bugs/a1g.tga
		blendfunc blend
   }
}

pattern-enhancer-laser
{
cull none
  {
  clampmap textures/coop_bugs/14.tga
  blendFunc GL_ONE GL_ONE
  tcMod scroll -0.5 0
  tcMod scale 4 1
  rgbGen wave Sin 1 0.2 10 2.5
  }
}



