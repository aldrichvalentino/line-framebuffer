default:
	@gcc -o main.exe main.c printChar.c printName.c shootPlane.c

run:
	sudo ./main.exe