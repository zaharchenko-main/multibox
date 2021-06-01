all:build install

CC := clang-12
FS := -s -O2 -fpie -Wall
BN := multibox

build:
	@rm -rf bin/$(BN) objs
	@mkdir -p bin objs

	@echo "[$(CC)] Compile   : $(BN) <= arch.c"
	@$(CC) -c src/arch.c -o objs/arch.o

	@echo "[$(CC)] Compile   : $(BN) <= basename.c"
	@$(CC) -c src/basename.c -o objs/basename.o

	@echo "[$(CC)] Compile   : $(BN) <= clear.c"
	@$(CC) -c src/clear.c -o objs/clear.o

	@echo "[$(CC)] Compile   : $(BN) <= dirname.c"
	@$(CC) -c src/dirname.c -o objs/dirname.o

	@echo "[$(CC)] Compile   : $(BN) <= echo.c"
	@$(CC) -c src/echo.c -o objs/echo.o

	@echo "[$(CC)] Compile   : $(BN) <= env.c"
	@$(CC) -c src/env.c -o objs/env.o

	@echo "[$(CC)] Compile   : $(BN) <= false.c"
	@$(CC) -c src/false.c -o objs/false.o

	@echo "[$(CC)] Compile   : $(BN) <= hostname.c"
	@$(CC) -c src/hostname.c -o objs/hostname.o

	@echo "[$(CC)] Compile   : $(BN) <= link.c"
	@$(CC) -c src/link.c -o objs/link.o

	@echo "[$(CC)] Compile   : $(BN) <= ln.c"
	@$(CC) -c src/ln.c -o objs/ln.o

	@echo "[$(CC)] Compile   : $(BN) <= logname.c"
	@$(CC) -c src/logname.c -o objs/logname.o

	@echo "[$(CC)] Compile   : $(BN) <= main.c"
	@$(CC) -c src/main.c -o objs/main.o

	@echo "[$(CC)] Compile   : $(BN) <= printenv.c"
	@$(CC) -c src/printenv.c -o objs/printenv.o

	@echo "[$(CC)] Compile   : $(BN) <= pwd.c"
	@$(CC) -c src/pwd.c -o objs/pwd.o

	@echo "[$(CC)] Compile   : $(BN) <= readlink.c"
	@$(CC) -c src/readlink.c -o objs/readlink.o

	@echo "[$(CC)] Compile   : $(BN) <= realpath.c"
	@$(CC) -c src/realpath.c -o objs/realpath.o

	@echo "[$(CC)] Compile   : $(BN) <= reset.c"
	@$(CC) -c src/reset.c -o objs/reset.o

	@echo "[$(CC)] Compile   : $(BN) <= rmdir.c"
	@$(CC) -c src/rmdir.c -o objs/rmdir.o

	@echo "[$(CC)] Compile   : $(BN) <= sleep.c"
	@$(CC) -c src/sleep.c -o objs/sleep.o

	@echo "[$(CC)] Compile   : $(BN) <= symlink.c"
	@$(CC) -c src/symlink.c -o objs/symlink.o

	@echo "[$(CC)] Compile   : $(BN) <= sync.c"
	@$(CC) -c src/sync.c -o objs/sync.o

	@echo "[$(CC)] Compile   : $(BN) <= test.c"
	@$(CC) -c src/test.c -o objs/test.o

	@echo "[$(CC)] Compile   : $(BN) <= true.c"
	@$(CC) -c src/true.c -o objs/true.o

	@echo "[$(CC)] Compile   : $(BN) <= tty.c"
	@$(CC) -c src/tty.c -o objs/tty.o

	@echo "[$(CC)] Compile   : $(BN) <= uname.c"
	@$(CC) -c src/uname.c -o objs/uname.o

	@echo "[$(CC)] Compile   : $(BN) <= unlink.c"
	@$(CC) -c src/unlink.c -o objs/unlink.o

	@echo "[$(CC)] Compile   : $(BN) <= usleep.c"
	@$(CC) -c src/usleep.c -o objs/usleep.o

	@echo "[$(CC)] Compile   : $(BN) <= whoami.c"
	@$(CC) -c src/whoami.c -o objs/whoami.o

	@echo "[$(CC)] Compile   : $(BN) <= yes.c"
	@$(CC) -c src/yes.c -o objs/yes.o


install:
	@$(CC) $(FS) objs/*.o -o bin/$(BN)
	@echo "[$(CC)] Install   : $(BN) => bin/$(BN)"


single-binary:
	@echo "[$(CC)] Build   : arch.c => bin/arch"
	@cat src/arch.c > tmp.c
	@echo "int main(int a,char **b){return arch_main(a,b);}" >> tmp.c
	@$(CC) $(FS) tmp.c -o bin/arch && rm -rf tmp.c

	@echo "[$(CC)] Build   : basename.c => bin/basename"
	@cat src/basename.c > tmp.c
	@echo "int main(int a,char **b){return basename_main(a,b);}" >> tmp.c
	@$(CC) $(FS) tmp.c -o bin/basename && rm -rf tmp.c

	@echo "[$(CC)] Build   : clear.c => bin/clear"
	@cat src/clear.c > tmp.c
	@echo "int main(int a,char **b){return clear_main(a,b);}" >> tmp.c
	@$(CC) $(FS) tmp.c -o bin/clear && rm -rf tmp.c

	@echo "[$(CC)] Build   : dirname.c => bin/dirname"
	@cat src/dirname.c > tmp.c
	@echo "int main(int a,char **b){return dirname_main(a,b);}" >> tmp.c
	@$(CC) $(FS) tmp.c -o bin/dirname && rm -rf tmp.c

	@echo "[$(CC)] Build   : echo.c => bin/echo"
	@cat src/echo.c > tmp.c
	@echo "int main(int a,char **b){return echo_main(a,b);}" >> tmp.c
	@$(CC) $(FS) tmp.c -o bin/echo && rm -rf tmp.c

	@echo "[$(CC)] Build   : env.c => bin/env"
	@cat src/env.c > tmp.c
	@echo "int main(int a,char **b){return env_main(a,b);}" >> tmp.c
	@$(CC) $(FS) tmp.c -o bin/env && rm -rf tmp.c

	@echo "[$(CC)] Build   : false.c => bin/false"
	@cat src/false.c > tmp.c
	@echo "int main(int a,char **b){return false_main(a,b);}" >> tmp.c
	@$(CC) $(FS) tmp.c -o bin/false && rm -rf tmp.c

	@echo "[$(CC)] Build   : hostname.c => bin/hostname"
	@cat src/hostname.c > tmp.c
	@echo "int main(int a,char **b){return hostname_main(a,b);}" >> tmp.c
	@$(CC) $(FS) tmp.c -o bin/hostname && rm -rf tmp.c

	@echo "[$(CC)] Build   : link.c => bin/link"
	@cat src/link.c > tmp.c
	@echo "int main(int a,char **b){return link_main(a,b);}" >> tmp.c
	@$(CC) $(FS) tmp.c -o bin/link && rm -rf tmp.c

	@echo "[$(CC)] Build   : ln.c => bin/ln"
	@cat src/ln.c > tmp.c
	@echo "int main(int a,char **b){return ln_main(a,b);}" >> tmp.c
	@$(CC) $(FS) tmp.c -o bin/ln && rm -rf tmp.c

	@echo "[$(CC)] Build   : logname.c => bin/logname"
	@cat src/logname.c > tmp.c
	@echo "int main(int a,char **b){return logname_main(a,b);}" >> tmp.c
	@$(CC) $(FS) tmp.c -o bin/logname && rm -rf tmp.c

	@echo "[$(CC)] Build   : printenv.c => bin/printenv"
	@cat src/printenv.c > tmp.c
	@echo "int main(int a,char **b){return printenv_main(a,b);}" >> tmp.c
	@$(CC) $(FS) tmp.c -o bin/printenv && rm -rf tmp.c

	@echo "[$(CC)] Build   : pwd.c => bin/pwd"
	@cat src/pwd.c > tmp.c
	@echo "int main(int a,char **b){return pwd_main(a,b);}" >> tmp.c
	@$(CC) $(FS) tmp.c -o bin/pwd && rm -rf tmp.c

	@echo "[$(CC)] Build   : readlink.c => bin/readlink"
	@cat src/readlink.c > tmp.c
	@echo "int main(int a,char **b){return readlink_main(a,b);}" >> tmp.c
	@$(CC) $(FS) tmp.c -o bin/readlink && rm -rf tmp.c

	@echo "[$(CC)] Build   : realpath.c => bin/realpath"
	@cat src/realpath.c > tmp.c
	@echo "int main(int a,char **b){return realpath_main(a,b);}" >> tmp.c
	@$(CC) $(FS) tmp.c -o bin/realpath && rm -rf tmp.c

	@echo "[$(CC)] Build   : reset.c => bin/reset"
	@cat src/reset.c > tmp.c
	@echo "int main(int a,char **b){return reset_main(a,b);}" >> tmp.c
	@$(CC) $(FS) tmp.c -o bin/reset && rm -rf tmp.c

	@echo "[$(CC)] Build   : rmdir.c => bin/rmdir"
	@cat src/rmdir.c > tmp.c
	@echo "int main(int a,char **b){return rmdir_main(a,b);}" >> tmp.c
	@$(CC) $(FS) tmp.c -o bin/rmdir && rm -rf tmp.c

	@echo "[$(CC)] Build   : sleep.c => bin/sleep"
	@cat src/sleep.c > tmp.c
	@echo "int main(int a,char **b){return sleep_main(a,b);}" >> tmp.c
	@$(CC) $(FS) tmp.c -o bin/sleep && rm -rf tmp.c

	@echo "[$(CC)] Build   : symlink.c => bin/symlink"
	@cat src/symlink.c > tmp.c
	@echo "int main(int a,char **b){return symlink_main(a,b);}" >> tmp.c
	@$(CC) $(FS) tmp.c -o bin/symlink && rm -rf tmp.c

	@echo "[$(CC)] Build   : sync.c => bin/sync"
	@cat src/sync.c > tmp.c
	@echo "int main(int a,char **b){return sync_main(a,b);}" >> tmp.c
	@$(CC) $(FS) tmp.c -o bin/sync && rm -rf tmp.c

	@echo "[$(CC)] Build   : test.c => bin/test"
	@cat src/test.c > tmp.c
	@echo "int main(int a,char **b){return test_main(a,b);}" >> tmp.c
	@$(CC) $(FS) tmp.c -o bin/test && rm -rf tmp.c

	@echo "[$(CC)] Build   : true.c => bin/true"
	@cat src/true.c > tmp.c
	@echo "int main(int a,char **b){return true_main(a,b);}" >> tmp.c
	@$(CC) $(FS) tmp.c -o bin/true && rm -rf tmp.c

	@echo "[$(CC)] Build   : tty.c => bin/tty"
	@cat src/tty.c > tmp.c
	@echo "int main(int a,char **b){return tty_main(a,b);}" >> tmp.c
	@$(CC) $(FS) tmp.c -o bin/tty && rm -rf tmp.c

	@echo "[$(CC)] Build   : uname.c => bin/uname"
	@cat src/uname.c > tmp.c
	@echo "int main(int a,char **b){return uname_main(a,b);}" >> tmp.c
	@$(CC) $(FS) tmp.c -o bin/uname && rm -rf tmp.c

	@echo "[$(CC)] Build   : unlink.c => bin/unlink"
	@cat src/unlink.c > tmp.c
	@echo "int main(int a,char **b){return unlink_main(a,b);}" >> tmp.c
	@$(CC) $(FS) tmp.c -o bin/unlink && rm -rf tmp.c

	@echo "[$(CC)] Build   : usleep.c => bin/usleep"
	@cat src/usleep.c > tmp.c
	@echo "int main(int a,char **b){return usleep_main(a,b);}" >> tmp.c
	@$(CC) $(FS) tmp.c -o bin/usleep && rm -rf tmp.c

	@echo "[$(CC)] Build   : whoami.c => bin/whoami"
	@cat src/whoami.c > tmp.c
	@echo "int main(int a,char **b){return whoami_main(a,b);}" >> tmp.c
	@$(CC) $(FS) tmp.c -o bin/whoami && rm -rf tmp.c

	@echo "[$(CC)] Build   : yes.c => bin/yes"
	@cat src/yes.c > tmp.c
	@echo "int main(int a,char **b){return yes_main(a,b);}" >> tmp.c
	@$(CC) $(FS) tmp.c -o bin/yes && rm -rf tmp.c


clean:
	@echo "[*] Cleaning   : bin, libs, obj, objs"
	@rm -rf bin libs obj objs
