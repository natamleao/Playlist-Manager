/***************************************************** PUBLIC INTERFACE *******************************************************/

#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "music.h"

typedef struct _playList PlayList;

/**
 * @brief Cria uma nova playlist vazia
 * 
 * @return PlayList* Ponteiro para a playlist criada
 */
PlayList *PlayListCreate();

/**
 * @brief Retorna o número de músicas na playlist
 * 
 * @param playList Ponteiro para a playlist
 * @return unsigned int Quantidade de músicas
 */
unsigned int PlayListGetSize(PlayList *playList);

/**
 * @brief Retorna a capacidade da playlist (número de músicas que cabem)
 * 
 * @param playList Ponteiro para a playlist
 * @return unsigned int Capacidade da playlist
 */
unsigned int PlayListGetCapacity(PlayList *playList);

/**
 * @brief Retorna a primeira música da playlist
 * 
 * @param playList Ponteiro para a playlist
 * @return Music* Ponteiro para a primeira música
 */
Music *PlayListGetBegin(PlayList *playList);

/**
 * @brief Retorna a última música da playlist
 * 
 * @param playList Ponteiro para a playlist
 * @return Music* Ponteiro para a última música
 */
Music *PlayListGetEnd(PlayList *playList);

/**
 * @brief Define o número de músicas na playlist
 *
 * @param playList Ponteiro para a playlist
 * @param size Novo tamanho da playlist
 */
void PlayListSetSize(PlayList *playList, unsigned int size);

/**
 * @brief Define o número de músicas que cabem na playlist
 *
 * @param playList Ponteiro para a playlist
 * @param capacity Nova capacidade da playlist
 */
void PlayListSetCapacity(PlayList *playList, unsigned int capacity);

/**
 * @brief Define a primeira música da playlist
 *
 * @param playList Ponteiro para a playlist
 * @param begin Ponteiro para a música que será o início
 */
void PlayListSetBegin(PlayList *playList, Music *begin);

/**
 * @brief Define a última música da playlist
 *
 * @param playList Ponteiro para a playlist
 * @param end Ponteiro para a música que será o fim
 */
void PlayListSetEnd(PlayList *playList, Music *end);

/**
 * @brief Adiciona uma nova música à playlist
 * 
 * @param playList Ponteiro para a playlist
 * @param name Nome do artista
 * @param music Nome da música
 * @param time Duração da música (em segundos)
 * @param f Flag para saber se não houve problemas ao adicionar
 */
void PlayListAdd(PlayList *playList, char *name, char *music, unsigned int time, int *f);

/**
 * @brief "Toca" a playlist, imprimindo informações das músicas
 * 
 * @param playList Ponteiro para a playlist
 * @param numberTimes Número de vezes que a playlist deve ser percorrida
 * @param f Flag para saber se não houve problemas ao tocar
 */
void PlayListplay(PlayList *playList, unsigned int numberTimes, int *f);

/**
 * @brief Remove a primeira ocorrência de uma música pelo nome
 * 
 * @param playList Ponteiro para a playlist
 * @param music Nome da música a ser removida
 * @param f Flag para saber se não houve problemas ao remover
 */
void PlayListRemove(PlayList *playList, char *music, int *f);

/**
 * @brief Carrega músicas de um arquivo texto para a playlist
 * 
 * Formato do arquivo:
 * Artista;Musica;Duracao
 * 
 * @param playList Ponteiro para a playlist
 * @param fileName Nome do arquivo
 * @param f Flag para saber se não houve problemas ao adicionar
 * @param h Flag para saber se não houve problemas ao adicionar pelo arquivo
 */
void PlayListLoadFromFile(PlayList *playList, char *fileName, int *f, int *h);

/**
 * @brief Ordena a playlist pelo tempo de duração das músicas
 * 
 * @param playList Ponteiro para a playlist
 */
void PlayListSortByDuration(PlayList *playList);

/**
 * @brief Busca por uma música na playlist
 * 
 * @param playList Ponteiro para a playlist
 * @param music A música procurada
 * @param f Flag para saber se a música foi encontrada
 */
Music *PlayListSearch(PlayList *playList, char *music, int *f);

/**
 * @brief Salva a playlist em um arquivo
 * 
 * @param playList Ponteiro para a playlist
 * @param fileName O nome do arquivo onde a playlist será salva
 * @param f Flag para verificar se o arquivo foi salvo 
 */
void PlayListSaveToFile(PlayList *playList, char *fileName, int *f);

/**
 * @brief Estatísticas da playlist (música mais longa, música mais curta, duração total e média)
 * 
 * @param playList Ponteiro para a playlist
 */
void PlayListStats(PlayList *playList);

/**
 * @brief Imprime todas as músicas da playlist
 * 
 * @param playList Ponteiro para a playlist
 */
void PlayListPrint(PlayList *playList);

/**
 * @brief Libera toda a memória da playlist
 * 
 * @param playList Ponteiro para a playlist
 * @param f Flag para saber se não houve problemas ao remover
 */
void PlayListDestroy(PlayList *playList, int *f);

#endif

/******************************************************************************************************************************/