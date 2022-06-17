#include "funciones.h"

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

int ValidarNombre(char nombre[]);
int ValidarAnio(int anio);
int ValidarMes(int anio, int mes);
int ValidarDia(int anio, int mes,int dia);

int ValidarExistenciaConsulta(int idConsulta,sConsulta consultas[],int tamanio);
int ValidarEstadoDeConsulta(int posicion,int estadoConsulta,sConsulta consultas[],int tamanio);
int ValidarIdMedico(int idMedico, sConsulta consultas[],int tamanio);
int ValidarExistenciaMedico(int idIngresado,sMedico medicos[],int tamanioMedicos);

#endif /* VALIDACIONES_H_ */

