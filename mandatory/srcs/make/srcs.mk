# MAIN
SRCS_PATH = ./srcs/
SRCS = main_bonus.c

# DOORS
SRCS_PATH += ./srcs/doors/
SRCS += animate_doors.c
SRCS += init_doors.c
SRCS += interact_doors.c
SRCS += render_doors.c

# EFFECTS
SRCS_PATH += ./srcs/effects/
SRCS += effects.c
SRCS += impact.c

# ENEMIES
SRCS_PATH += ./srcs/enemies/
SRCS += animate_enemies.c
SRCS += animate_skeleton.c
SRCS += animate_werewolf.c
SRCS += animate_zombie.c
SRCS += combat_enemies.c
SRCS += init_enemies.c
SRCS += enemies.c
SRCS += move_enemies.c
SRCS += raycast_enemies.c
SRCS += utils_enemies.c

# HUD
SRCS_PATH += ./srcs/hud/
SRCS += health.c
SRCS += hud.c
SRCS += m_enemies.c
SRCS += m_player.c
SRCS += minimap.c

# IMAGES
SRCS_PATH += ./srcs/img/
SRCS += destroy_effects.c
SRCS += destroy_enemies.c
SRCS += destroy_magick.c
SRCS += destroy_player.c
SRCS += destroy_sprites.c
SRCS += destroy_textures.c
SRCS += img.c
SRCS += load_effects.c
SRCS += load_enemies.c
SRCS += load_magick.c
SRCS += load_player.c
SRCS += load_sprites.c
SRCS += load_textures.c

# INPUTS
SRCS_PATH += ./srcs/inputs/
SRCS += keypress_bonus.c
SRCS += keyrelease_bonus.c
SRCS += mousehook_bonus.c

# LOOP
SRCS_PATH += ./srcs/loop/
SRCS += loop.c

# MOVEMENT
SRCS_PATH += ./srcs/move/
SRCS += move.c
SRCS += new_pos.c

# PARSING
SRCS_PATH += ./srcs/parsing/
SRCS += check_data_bonus.c
SRCS += check_data_utils_bonus.c
SRCS += check_map_bonus.c
SRCS += check_map_nl_bonus.c
SRCS += get_data_bonus.c
SRCS += get_map_bonus.c
SRCS += parsing_bonus.c
SRCS += read_file_bonus.c

# PLAYER
SRCS_PATH += ./srcs/player/
SRCS += attack.c
SRCS += combat.c
SRCS += idle.c
SRCS += init_player.c
SRCS += magick.c
SRCS += player.c
SRCS += running.c
SRCS += spell.c
SRCS += walking.c
SRCS += weapons.c

# RAYCASTING
SRCS_PATH += ./srcs/raycasting/
SRCS += ceiling.c
SRCS += central_ray.c
SRCS += double_wall.c
SRCS += floor.c
SRCS += init_ray.c
SRCS += raycasting.c
SRCS += wall.c

# SCREENS
SRCS_PATH += ./srcs/screens/
SRCS += screens.c
SRCS += img_screens.c

# SPRITES
SRCS_PATH += ./srcs/sprites/
SRCS += animate_sprite.c
SRCS += draw_sprite.c
SRCS += init_sprite.c
SRCS += sort_sprites.c
SRCS += render_sprites.c

# UTILS
SRCS_PATH += ./srcs/utils/
SRCS += colors.c
SRCS += draw_forms.c
SRCS += exit_bonus.c
SRCS += fps_counter_bonus.c
SRCS += free_bonus.c
SRCS += garbage_collector_bonus.c
SRCS += print_bonus.c
SRCS += put_pix.c
SRCS += upscale_img.c
