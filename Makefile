all:
	gcc ./files/main.c ./files/select.c ./files/init.c ./files/unselect.c ./files/commit.c ./files/logs.c ./files/reset.c ./files/stash.c ./files/status.c -o main