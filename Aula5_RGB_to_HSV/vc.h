//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//           INSTITUTO POLITÉCNICO DO CÁVADO E DO AVE
//                          2011/2012
//             ENGENHARIA DE SISTEMAS INFORMÁTICOS
//                    VISÃO POR COMPUTADOR
//
//             [  DUARTE DUQUE - dduque@ipca.pt  ]
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#define VC_DEBUG
#define MAX3(a,b,c) (a>(b>c?b:c)?a:(b>c?b:c))	//MAX = MAXIMO{R,G,B}
#define MIN3(a,b,c) (a<(b<c?b:c)?a:(b<c?b:c))	//MIN = MINIMO{R,G,B}
#define MAX(a,b)	(a>b?a:b)
#define MIN(a,b)	(a<b?a:b)



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//                   ESTRUTURA DE UMA IMAGEM
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


typedef struct {
	unsigned char *data;
	int width, height;
	int channels;			// Binário/Cinzentos=1; RGB=3
	int levels;				// Binário=1; Cinzentos [1,255]; RGB [1,255]
	int bytesperline;		// width * channels
} IVC;


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//                    PROTÓTIPOS DE FUNÇÕES
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// FUNÇÕES: ALOCAR E LIBERTAR UMA IMAGEM
IVC *vc_image_new(int width, int height, int channels, int levels);
IVC *vc_image_free(IVC *image); 										//liberta a memoria

// FUNÇÕES: LEITURA E ESCRITA DE IMAGENS (PBM, PGM E PPM)
IVC *vc_read_image(char *filename);
int vc_write_image(char *filename, IVC *image);

//FUNÇÔES: ESPAÇOS DE COR
int vc_gray_negative(IVC *srcdst);
int vc_rgb_negative(IVC *srtdst);

//FUNÇÕES: DECOMPOR IMAGEM (Remover cores)
int vc_rgb_get_red_gray(IVC *srcdst);
int vc_rgb_get_green_gray(IVC *srcdst);
int vc_rgb_get_blue_gray(IVC *srcdst);

int vc_rgb_to_gray(IVC *src, IVC *dst);

//FUNÇÃO: ESPAÇO RBG (HSV)
int vc_rgb_to_hsv(IVC *srcdst);
int vc_rgb_to_hsv_get_yellow(IVC *srcdst); //Extrair Amarelo