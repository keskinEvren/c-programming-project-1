run: main.exe $(seed)

main.exe: main.o
     gcc -o main.exe main.o

main.o: main.c
     gcc -c main.c matrixLib.c

clean:
     rm main.o main.exe