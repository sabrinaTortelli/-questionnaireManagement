//
// Created by Sabrina on 24/04/2020.
//

#include "questions.h"

#include <cstdlib>


int chooseRandomCode(){
    int x = rand() % 100;
    return x;
}

void insertAtDisciplineEnd(QuestionsData* &list, QuestionsData* element, QuestionnaireData* &lists, std::string discipline){
    if (list == nullptr){
        list = element;
        return;
    }
    QuestionsData* last = list;
    while (last->next != nullptr){
        last = last->next;
    }
    last->next = element;
    if(lists->disciplineName == discipline){
        lists->questions = list;
    }
}

Questions createQuestion(std::string questionHeader,
                         std::string answer01, std::string answer02, std::string answer03, std::string answer04,
                         int rigthAnswer, QuestionsData* &list) {
    Questions questions  = new QuestionsData;
    questions->questionHeader = questionHeader;
    questions->id = chooseRandomCode();
    questions->answers[0] = answer01;
    questions->answers[1] = answer02;
    questions->answers[2] = answer03;
    questions->answers[3] = answer04;
    questions->rigthAnswer = rigthAnswer-1;
    return questions;
}

void showQuestionList(QuestionsData* list){
    QuestionsData* element = list;
    if(element == nullptr){
        std::cout << "A lista esta vazia!" << std::endl;
    } else {
        while (element != nullptr) {
            std::cout << element->id << " - " << element->questionHeader << std::endl;
            for (int i = 0; i < 4; i++) {
                std::cout << element->answers[i] << std::endl;
            }
            std::cout << element->rigthAnswer << std::endl;
            element = element->next;
        }
        std::cout << "********************" << std::endl;
    }
}

void removeQuestionsList(QuestionsData* lists) {
    QuestionsData* element = lists;
    while(element != nullptr){
        QuestionsData *garbage = element->next;
        free(element);
        element = garbage;
    }
}

Questions updateQuestion(std::string questionHeader,
                         std::string answer01, std::string answer02, std::string answer03, std::string answer04,
                         int rigthAnswer, int id, QuestionsData* &list) {
    QuestionsData *element = list;
    if (element == nullptr) {
        std::cout << "A lista esta vazia!" << std::endl;
    } else {
        while (element != nullptr) {
            if (element->id == id) {
                element->questionHeader = questionHeader;
                element->answers[0] = answer01;
                element->answers[1] = answer02;
                element->answers[2] = answer03;
                element->answers[3] = answer04;
                element->rigthAnswer = rigthAnswer - 1;
            }
            element = element->next;
        }
        std::cout << "********************" << std::endl;
    }
    return element;
}

Questions listRemove(QuestionsData *current){
    if (current == nullptr){
        return nullptr;
    }
    QuestionsData *top;
    top = current->next;
    free(current);
    current = nullptr;
    return top;
}

Questions listRemoveForId(QuestionsData *current, int id){
    QuestionsData *list = current;
    QuestionsData *ant = nullptr;
    if (list->id == id){
        list = listRemove(current);
        return list;
    }
    while (list != nullptr && list->id != id){
        ant = list;
        list =list->next;
    }
    if (list == nullptr){
        return list;
    }
    ant->next = list->next;
    free(list);
    list = nullptr;
    return list;
}

Questions find (QuestionsData* list, int id){
    QuestionsData* element;
    for (element=list; element!= nullptr; element=element->next){
        if (element->id == id){
            return element;
        }
    }
    return nullptr;
}