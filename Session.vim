let SessionLoad = 1
let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/Documents/C++/HacknSlash
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
let s:shortmess_save = &shortmess
if &shortmess =~ 'A'
  set shortmess=aoOA
else
  set shortmess=aoO
endif
badd +1 Session.vim
badd +12 main.cpp
badd +83 src/Game.cpp
badd +8 inc/Game.hpp
badd +1 src/Input.cpp
badd +1 inc/Input.h
badd +6 src/GameObject.cpp
badd +7 inc/GameObject.h
badd +11 src/TextureManager.cpp
badd +9 inc/TextureManager.h
badd +40 src/Map.cpp
badd +2 inc/Map.h
badd +34 inc/ECS/SpriteComponent.h
badd +6 inc/ECS/Components.h
badd +165 inc/ECS/ECS.h
badd +25 inc/ECS/TransformComponet.h
badd +30 inc/Vector2D.h
badd +84 src/Vector2D.cpp
badd +33 inc/ECS/KeyboardControler.h
badd +32 inc/ECS/ColliderComponent.h
badd +30 src/Collision.cpp
badd +13 inc/Collision.h
badd +55 inc/ECS/TileComponent.h
badd +0 inc/ECS/ECS.cpp
badd +1 inc
argglobal
%argdel
$argadd inc/ECS/ECS.cpp
edit src/Game.cpp
argglobal
balt inc/ECS/TileComponent.h
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 83 - ((21 * winheight(0) + 22) / 45)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 83
normal! 045|
lcd ~/Documents/C++/HacknSlash
tabnext 1
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0 && getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20
let &shortmess = s:shortmess_save
let s:sx = expand("<sfile>:p:r")."x.vim"
if filereadable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &g:so = s:so_save | let &g:siso = s:siso_save
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
