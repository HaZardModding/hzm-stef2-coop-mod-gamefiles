//--------------------------------------------------------------------
// Mod Additional Textures
//--------------------------------------------------------------------
coop_use
{
   nomipmaps
   nopicmip
   cull none
   {
		map textures/coop_mod/use.tga
		blendfunc blend
		alphaFunc GT0
		alphaGen global
   }
}
coop_modulate
{
   nomipmaps
   nopicmip
   cull none
   {
		map textures/coop_mod/modulate.tga
		blendfunc blend
		alphaFunc GT0
		alphaGen global
   }
}
coop_destroy
{
   nomipmaps
   nopicmip
   cull none
   {
		map textures/coop_mod/destroy.tga
		blendfunc blend
		alphaFunc GT0
		alphaGen global
   }
}
coop_bomb
{
   nomipmaps
   nopicmip
   cull none
   {
		map textures/coop_mod/bomb.tga
		blendfunc blend
		alphaFunc GT0
		alphaGen global
   }
}

