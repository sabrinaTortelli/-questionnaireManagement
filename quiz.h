//
// Created by Sabrina on 24/04/2020.
//

#pragma once

#include <iostream>

struct QuestionsData{
    std::string questionHeader;
    std::string answers[4];
    int rigthAnswer;
    int id=0;
    struct QuestionsData *next = nullptr;
};

typedef struct QuestionsData* Questions;

struct QuestionnaireData{
    std::string title;
    std::string disciplineName;
    int numberOfQuestions;
    struct QuestionnaireData *next = nullptr;
    Questions questions;
};

typedef struct QuestionnaireData* Quiz;

/**
 * Inserir a disciplina na lista de disciplinas
 * @param list lista de disciplinas
 * @param element ponteiro para um elemento da lista
 */
void insertAtEnd(QuestionnaireData* &list, QuestionnaireData* element);

/**
 * Cria lista de disciplinas
 * @param title titulo da disciplina
 * @param disciplineName nome da disciplina
 * @param list lista de disciplinas
 */
void createQuiz(std::string title, std::string disciplineName, QuestionnaireData* &list);

/**
 * Mostra lista de disciplinas
 * @param list lista de disciplinas
 */
void showQuizList(QuestionnaireData* list);

/**
 * Remove todos os elementos da lista específica da disciplina e remove também a disciplina da lista de disciplinas
 * @param list lista das disciplinas
 * @param lists lista de questões
 * @param discipline disciplina que se quer deletar
 */
void removeAll(QuestionnaireData *&list, QuestionsData* &lists, std::string discipline);

/**
 * Atualiza um elemento da lista de disciplinas
 * @param newTitle novo título
 * @param discipline disciplina que quer atualizar
 * @param newDisciplineName novo nome da disciplina
 * @param list lista de disciplinas
 * @return retorna a lista de disciplinas
 */
Quiz updateQuiz(std::string newTitle, std::string discipline, std::string newDisciplineName, QuestionnaireData* &list);

/**
 * Acha uma discilpina pelo nome
 * @param list lista de disciplinas
 * @param disciplineName nome da disciplina que se quer buscar
 * @return retorna o elemento da disciplina se achar e retorna vazio se não achar
 */
Quiz findElement (QuestionnaireData* list, std::string disciplineName);