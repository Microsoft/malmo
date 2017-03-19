// --------------------------------------------------------------------------------------------------
//  Copyright (c) 2016 Microsoft Corporation
//  
//  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
//  associated documentation files (the "Software"), to deal in the Software without restriction,
//  including without limitation the rights to use, copy, modify, merge, publish, distribute,
//  sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//  
//  The above copyright notice and this permission notice shall be included in all copies or
//  substantial portions of the Software.
//  
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
//  NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
//  DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
// --------------------------------------------------------------------------------------------------

#ifndef MISSIONSPEC_H
#define MISSIONSPEC_H

#ifdef __cplusplus
extern "C" {
#endif

typedef void* ptMissionSpec;

// constructor
ptMissionSpec new_mission_spec();

// destructor
void free_mission_spec(ptMissionSpec mission_spec);

// methods
void mission_spec_time_limit_in_seconds(ptMissionSpec mission_spec, float s);


// -------------------- settings for the server -------------------------

void mission_spec_set_summary            (ptMissionSpec pt, const char* summary);
void mission_spec_time_limit_in_seconds  (ptMissionSpec pt, float s);
void mission_spec_create_default_terrain (ptMissionSpec pt);
void mission_spec_set_world_seed         (ptMissionSpec pt, const char *seed);
void mission_spec_force_world_reset      (ptMissionSpec pt);
void mission_spec_set_time_of_day        (ptMissionSpec pt, int t, int allowTimeToPass);
void mission_spec_draw_block             (ptMissionSpec pt, int x, int y, int z, const char* blockType);
void mission_spec_draw_cuboid            (ptMissionSpec pt, int x1, int y1, int z1, int x2, int y2, int z2, const char* blockType);
void mission_spec_draw_item              (ptMissionSpec pt, int x, int y, int z, const char* itemType);
void mission_spec_draw_sphere            (ptMissionSpec pt, int x, int y, int z, int radius, const char* blockType);
void mission_spec_draw_line              (ptMissionSpec pt, int x1, int y1, int z1, int x2, int y2, int z2, const char* blockType);

// -------------------- settings for the agents -------------------------

void mission_spec_start_at                     (ptMissionSpec pt, float x, float y, float z);
void mission_spec_start_at_with_pitch_and_yaw  (ptMissionSpec pt, float x, float y, float z, float pitch, float yaw);
void mission_spec_end_at                       (ptMissionSpec pt, float x, float y, float z, float tolerance);
void mission_spec_set_mode_to_creative         (ptMissionSpec pt);
void mission_spec_set_mode_to_spectator        (ptMissionSpec pt);
void mission_spec_request_video                (ptMissionSpec pt, int width, int height);
void mission_spec_request_video_with_depth     (ptMissionSpec pt, int width, int height);
void mission_spec_set_viewpoint                (ptMissionSpec pt, int viewpoint);
void mission_spec_reward_for_reaching_position (ptMissionSpec pt, float x, float y, float z, float amount, float tolerance);
void mission_spec_observe_recent_commands      (ptMissionSpec pt);
void mission_spec_observe_hot_bar              (ptMissionSpec pt);
void mission_spec_observe_full_inventory       (ptMissionSpec pt);
void mission_spec_observe_grid                 (ptMissionSpec pt, int x1, int y1, int z1, int x2, int y2, int z2, const char* name);
void mission_spec_observe_distance             (ptMissionSpec pt, float x, float y, float z, const char* name);
void mission_spec_observe_chat                 (ptMissionSpec pt);

// -------------------- settings for the agents : command handlers -------------------------

void mission_spec_remove_all_command_handlers            (ptMissionSpec pt);
void mission_spec_allow_all_continuous_movement_commands (ptMissionSpec pt);
void mission_spec_allow_continuous_movement_command      (ptMissionSpec pt, const char* verb);
void mission_spec_allow_all_discrete_movement_commands   (ptMissionSpec pt);
void mission_spec_allow_discrete_movement_command        (ptMissionSpec pt, const char* verb);
void mission_spec_allow_all_absolute_movement_commands   (ptMissionSpec pt);
void mission_spec_allow_absolute_movement_command        (ptMissionSpec pt, const char* verb);
void mission_spec_allow_all_inventory_commands           (ptMissionSpec pt);
void mission_spec_allow_inventory_command                (ptMissionSpec pt, const char* verb);
void mission_spec_allow_all_chat_commands                (ptMissionSpec pt);

// ------------------------- information --------------------------------------

void mission_spec_get_summary                  (ptMissionSpec pt);
int  mission_spec_get_number_of_agents         (ptMissionSpec pt);
int  mission_spec_is_video_requested           (ptMissionSpec pt, int role);
int  mission_spec_get_video_width              (ptMissionSpec pt, int role);
int  mission_spec_get_video_height             (ptMissionSpec pt, int role);
int  mission_spec_get_video_channels           (ptMissionSpec pt, int role);
void mission_spec_get_list_of_command_handlers (ptMissionSpec pt, int role);
void mission_spec_get_allowed_commands         (ptMissionSpec pt, int role, const char* command_handler);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif // MISSIONSPEC_H
