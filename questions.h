//
// Created by Sabrina on 24/04/2020.
//

#pragma once

#include "quiz.h"

/**
 * insere os dados das questões em uma lista específica da questão
 * @param list lista de questões
 * @param element ponteiro para elemento da lista de questões
 * @param lists lista de disciplinas
 * @param discipline disciplina que se quer adicionar a questão
 */
void insertAtDisciplineEnd(QuestionsData* &list, QuestionsData* element, QuestionnaireData* &lists, std::string discipline);

/**
 * Cria uma nova questão
 * @param questionHeader cabeçalho da questão
 * @param answer01 resposta 01
 * @param answer02 resposta 02
 * @param answer03 resposta 03
 * @param answer04 resposta 04
 * @param rigthAnswer indica qual o numero da questão certa
 * @param list lista de questões
 * @return retorna a lista de questões
 */
Questions createQuestion(std::string questionHeader,
                         std::string answer01, std::string answer02, std::string answer03, std::string answer04,
                         int rigthAnswer, QuestionsData* &list);

/**
 * Mostra na tela as listas de questões
 * @param list lista de questões
 */
void showQuestionList(QuestionsData* list);

/**
 * Remove a lista de questões inteira
 * @param lists lista de questões
 */
void removeQuestionsList(QuestionsData* lists);

/**
 * Atualiza um elemento da lista de questões
 * @param questionHeader novo cabeçalho da questão
 * @param answer01 nova resposta 01
 * @param answer02 nova resposta 02
 * @param answer03 nova resposta 03
 * @param answer04 nova resposta 04
 * @param rigthAnswer nova questão correta
 * @param id índice que identifica a questão que deve ser atualizada
 * @param list lista de questões
 * @return retorna a lista
 */
Questions updateQuestion(std::string questionHeader,
                         std::string answer01, std::string answer02, std::string answer03, std::string answer04,
                         int rigthAnswer, int id, QuestionsData* &list);

/**
 * Remove um elemento atual
 * @param current lista de questões
 * @return retorna a lista
 */
Questions listRemove(QuestionsData *current);

/**
 * Remove um elemento da lista de questões pelo id
 * @param current lista de questões
 * @param id id que quer remover
 * @return retorna a lista
 */
Questions listRemoveForId(QuestionsData *current, int id);

/**
 * Acha uma questão pelo id
 * @param list lista de questões
 * @param id índice da questão que se deseja achar
 * @return retorna o elemento da lista se achar ou retorna vazio se não achar
 */
Questions find (QuestionsData* list, int id);

/**
 * Gera números aleatórios para o id
 * @return retorna um número aleatório de acordo com a semente de tempo
 */
int chooseRandomCode();
