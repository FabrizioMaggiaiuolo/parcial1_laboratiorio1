#ifndef FUNCIONES_H_
#define FUNCIONES_H_

typedef struct {
	int dia;
	int mes;
	int anio;

} sFecha;

typedef struct {
	int idDiagnostico;
	char descripcion[50];

} sDiagnostico;

typedef struct {
	int idConsulta;
	int idMedico;
	char nombrePaciente[52];
	sFecha fechaDeAtencion;
	sDiagnostico diagnostico;
	int estado;

} sConsulta;

typedef struct {
	int idHospital;
	char nombre[20];
	int cantidadDeMedicos;

} sHospital;

typedef struct {
	int idEspecialidad;
	char descripcion[50];

} sEspecialidad;

typedef struct {
	int idMedico;
	char nombre[52];
	sEspecialidad especialidad;
	int cantidadConsultas;
	int estado;
	int idHospital;

} sMedico;

//1
/// \brief Agrega una consulta en el array de consultas
void AltaConsulta(sConsulta consultas[],int tamanio,int ids);

/// \brief Busca una posicion libre en el array de consultas
/// \return retorna -1 si no se encontro o el numero de la posicion donde se guardara la consulta
int BuscarConsultaLibre(sConsulta consultas[],int tamanio);

/// \brief Pide todos los datos para generar la consulta
/// \return La consulta creada
sConsulta cargarConsulta(sConsulta consultas[],int tamanio,int ids);

/// \brief Pide el ingreso de fechas
/// \return El objeto consulta con las fechas cargadas
sConsulta IngresoDeFecha(sConsulta consultaAuxiliar);
//2
/// \brief Imprime el submenu para las modificaciones
void MenuModificarConsulta(sConsulta consultas[],int tamanio);

/// \brief Modifica el nombre del paciente de la consulta ingresada por uno nuevo
/// \param idConsultaIngresada Esta es la consulta que se modificara
void ModificarNombrePaciente(int idConsultaIngresada,sConsulta consultas[],int tamanio);

/// \brief Modifica la fecha de la consulta ingresada por una nuevo
/// \param idConsultaIngresada Esta es la consulta que se modificara
void ModificarFecha(int idConsultaIngresada,sConsulta consultas[],int tamanio);

/// \brief Modifica el medico de la consulta ingresada por uno nuevo
/// \param idConsultaIngresada Esta es la consulta que se modificara
void ModificarMedico(int idConsultaIngresada,sConsulta consultas[],int tamanio);

//3
/// \brief Da una baja logica al id de la consulta que se ingrese
void CancerlarConsulta(sConsulta consultas[],int tamanio);

//4
/// \brief Se le asigna un diagnostico y medico a una consulta
void Diagnosticar(sConsulta consultas[],int tamanio,sMedico medicos[],int tamanioMedicos);

//5
/// \brief Lista del menu de posibles listas
void MenuListar(sConsulta consultas[], int tamanio ,sMedico medicos[],int tamanioMedicos, sEspecialidad especialidades[], int cantidadEspecialidades, sHospital hospitales[], int tamaniohospitales);

/// \brief Lista de todos los medicos
void ListarTodosMedicos(sMedico medicos[],int tamanioMedicos);

/// \brief Lista de todas las consultas
void ListarTodasConsultas(sConsulta consultas[],int tamanio);

/// \brief Lista de todos los medicos con sus consultas
void ListarTodosMedicosConConsulta(sConsulta consultas[],int tamanio,sMedico medicos[],int tamanioMedicos);

/// \brief Lista de las consultas ordenas de la fecha mas cercana a las mas antigua
void ConsultasPorFecha(sConsulta consultas[],int tamanio);

/// \brief Lista de las consultas ya diagnosticadas
void ConsultasYaDiagnosticadas(sConsulta consultas[],int tamanio);

/// \brief Lista de todas las consultas desde el incio de la pandemia con el diagnostico Covid-19
void CasosCovid19DesdeInicioDePandemia(sConsulta consultas[],int tamanio,sMedico medicos[],int tamanioMedicos);

/// \brief Lista de las consultas ordenas alfabeticamente por especialidad del medico
void ConsultasOrdenadoEspecialidad(sConsulta consultas[],int tamanio,sMedico medicos[],int tamanioMedicos);

/// \brief Lista de las consultas entre 2 meses
/// \param num1 El mes mas chico a comparar
/// \param num2 El mes mas grande a comparar
void ConsultasEntreMesesEspecialidad(sConsulta consultas[],int tamanio,sMedico medicos[],int tamanioMedicos,int mes1, int mes2);

/// \brief Lista de los porcentajes de consultas de cada medico
void PorcentajeConsultasPorMedico(sConsulta consultas[],int tamanio,sMedico medicos[],int tamanioMedicos);

void EnfermedadMenosDiagnosticada(sConsulta consultas[],int tamanio);

void EspecialidadMasEstudiada(sMedico medicos[],int tamanioMedicos, sEspecialidad especialidades[],int tamanioEspecialidades);

void MostrarHospitalesYMedicos(sHospital hospitales[], int tamaniohospitales);

void MostrarConsultasHospital(sConsulta consultas[],int tamanio ,sMedico medicos[],int tamanioMedicos, sHospital hospitales[], int tamaniohospitales);

#endif /* FUNCIONES_H_ */

