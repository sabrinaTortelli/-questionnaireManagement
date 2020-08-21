//
// Created by Sabrina on 24/04/2020.
//

#include "quiz.h"
#include "questions.h"

void insertAtEnd(QuestionnaireData* &list, QuestionnaireData* element){
    if (list == nullptr){
        list = element;
        return;
    }
    QuestionnaireData* last = list;
    while (last->next != nullptr){
        last = last->next;
    }
    last->next = element;
}

void createQuiz(std::string title, std::string disciplineName, QuestionnaireData* &list) {
    Quiz quiz  = new QuestionnaireData;
    quiz->title = title;
    quiz->disciplineName = disciplineName;
    insertAtEnd(list, quiz);
}

void showQuizList(QuestionnaireData* list){
    QuestionnaireData* element = list;
    while (element != nullptr){
        std::cout << element->title << std::endl;
        element = element->next;
    }
    std::cout << "********************" << std::endl;
}

void removeAll(QuestionnaireData *&list, QuestionsData* &lists, std::string discipline) {
    removeQuestionsList(lists);
    QuestionnaireData* element = list;
    QuestionnaireData *garbage;
    while(element != nullptr){
        if(element->disciplineName == discipline){
            garbage = element->next;
            element->next = garbage->next;
            free(garbage);
        }
        element = element->next;
    }
}

Quiz updateQuiz(std::string newTitle, std::string discipline, std::string newDisciplineName, QuestionnaireData* &list){
    QuestionnaireData* element = list;
    if (element == nullptr) {
        std::cout << "A lista esta vazia!" << std::endl;
    } else {
        while (element != nullptr) {
            if (element->disciplineName == discipline) {
                element->title = newTitle;
                element->disciplineName = newDisciplineName;
            }
            element = element->next;
        }
        std::cout << "********************" << std::endl;
    }
    return element;
}

Quiz findElement (QuestionnaireData* list, std::string disciplineName){
    QuestionnaireData* element;
    for (element=list; element!= nullptr; element=element->next){
        if (element->disciplineName == disciplineName){
            return element;
        }
    }
    return nullptr;
}


