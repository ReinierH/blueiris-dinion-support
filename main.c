#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <rcpplus/rcpplus.h>
#include <rcpplus/rcpdefs.h>
#include <rcpplus/rcpcommand.h>
#include <rcpplus/pelcod.h>

#define PTZ_ADDRESS		1
#define CMD_DURATION 	150

int main(int argc, char*argv[]) {

	if(argc < 3) {
		fprintf(stderr, "usage: %s <ip> <command> \n", argv[0]);
		return(0);
	}

	const char* ip = argv[1]; argc--;
	const char* cmd = argv[2]; argc--;

	rcp_connect(ip);

	start_event_handler();

	client_register(RCP_USER_LEVEL_SERVICE, "service", RCP_REGISTRATION_TYPE_NORMAL, RCP_ENCRYPTION_MODE_PLAIN);

	if(strcmp(cmd, "UP") == 0) {
		pelcod_move_up(PTZ_ADDRESS, 0x3f);
	} else if(strcmp(cmd, "DOWN") == 0) {
		pelcod_move_down(PTZ_ADDRESS, 0x3f);
	} else if(strcmp(cmd, "LEFT") == 0) {
		pelcod_move_left(PTZ_ADDRESS, 0x3f);
	} else if(strcmp(cmd, "RIGHT") == 0) {
		pelcod_move_right(PTZ_ADDRESS, 0x3f);

	}

	usleep(CMD_DURATION*1000);

	pelcod_move_stop(PTZ_ADDRESS);	

	stop_event_handler();

	return(1);
}