
#include <mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	MYSQL *conn;
	int err;
	
	//Estructura especial para almacenar resultados de consultas
	MYSQL_RES *resultado;
	MYSQL_ROW row;
	char username[20];
	char consulta[80];
	
	//Creamos una conexion al servidor MYSQL
	conn = mysql_init(NULL);
	if (conn == NULL)
	{
		printf ("Error al crear la conexion: %u %s\n", mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	
	//Inicializar la conexión 
	conn = mysql_real_connect(conn, "localhost", "root", "mysql", "juego", 0, NULL, 0);
	if (conn == NULL)
	{
		printf ("Error al inicializar la conexion: %u %s\n", mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	
	//Pedir el nombre de usuario
	printf("Usuario para consultar puntos:\n");
	scanf("%s", username);
	
	//Consulta SQL para obtener los puntos de jugador
	sprintf(consulta, "SELECT points FROM player WHERE username='%s'", username);
	
	//Ejecutamos la consulta
	err = mysql_query(conn, consulta);
	if (err != 0)
	{
		printf("Error al realizar la consulta: %u %s\n", mysql_errno(conn), mysql_error(conn));
		mysql_close(conn);
		exit(1);
	}
	
	//Recogemos el resultado de la consulta
	resultado = mysql_store_result(conn);
	row = mysql_fetch_row(resultado);
	
	//Verificamos si el resultado contiene alguna fila
	if (row == NULL)
	{
		printf("%s no encontrado o no tiene puntos registrados. \n", username);
	}
	else
	{
		printf("%s tiene %s puntos. \n", username, row[0]);
	}
	
	mysql_free_result(resultado);
	mysql_close(conn);
	return 0;
}
