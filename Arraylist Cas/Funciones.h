
typedef struct
{
    int posicion;
    char nombre[50];
    int seguidores;
    char apodo[50];
}EClub;

EClub* newClub();
//void generarBinario(ArrayList* lista, FILE* bin)
void agregarClub(ArrayList* lista,EClub* club);
void mostrarClub(ArrayList* lista,EClub* club);
int cargarBinario( EClub* movie,ArrayList* lista);
void guardarBinario(EClub* club,ArrayList* lista);
void EliminarClub(ArrayList* lista, EClub* club);
void ModifocarClub(ArrayList* lista, EClub* club);
void PosicionEspecificada(ArrayList* lista, EClub* club);
int comparaPersonas(void* club,void* Equipo);
int LeerEquipos( FILE* Archivo,ArrayList* lista);
void VerificacionPos(ArrayList* lista,EClub* club,int aux);


