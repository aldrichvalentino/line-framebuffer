default:
	@gcc -o main.exe main.c printChar.c printName.c

run:
	sudo ./main.exe