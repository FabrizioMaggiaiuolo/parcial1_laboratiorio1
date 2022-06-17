#ifndef INPUTS_H_
#define INPUTS_H_

/*
typedef struct
{
	int id;
	char nombre[32];

}structura;
*/
int esNumerica(char cadena[]);

int GetInt(char mensaje[]);
float GetFloat(char mensaje[]);
char GetChar(char mensaje[]);
void GetString(char mensaje[],char copiar[]);

#endif /* INPUTS_H_ */
