#include "eventlist.h"

Event* create_event(time_t timestamp, int duration) {
    Event* new_event = (Event*)malloc(sizeof(Event));
    if (new_event == NULL) {
        fprintf(stderr, "Error: no se pudo asignar memoria para el evento\n");
        exit(EXIT_FAILURE);
    }
    new_event->timestamp = timestamp;
    new_event->duration = duration;
    new_event->prev = NULL;
    new_event->next = NULL;
    return new_event;
}

EventList* create_event_list() {
    EventList* list = (EventList*)malloc(sizeof(EventList));
    if (list == NULL) {
        fprintf(stderr, "Error: no se pudo asignar memoria para la lista de eventos\n");
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void add_event(EventList* list, time_t timestamp, int duration) {
    if(list == NULL){
        return;
    }

    Event* new_event = create_event(timestamp, duration);
    if(new_event == NULL){
        // free(list); NO DEBO HACER ESTO, pq aunq el evento era NULL, tengo q seguir usando la lista!
        return;
    }

    if(list->head == NULL){
        list->head = new_event;
        list->tail = new_event;
        return;
    }
    list->tail->next = new_event;
    new_event->prev = list->tail;
    list->tail = new_event;
    return;
}

void remove_expired_events(EventList* list, time_t current_time) {
    
    Event *Aux; 
    Aux = list->head;

    while(Aux != NULL){
        Event *toDelete = Aux;

        long int initialized = Aux->timestamp;
        int duration = Aux->duration;

        if(initialized + duration <= current_time){
            toDelete = Aux;
            Aux = Aux->next;

            
            if(toDelete == list->head){
                list->head = toDelete->next;
                // si la lista está vacía
                if(list->head != NULL){
                    list->head->prev = NULL;
                }
                
                }

                else if(toDelete == list->tail){
                    list->tail = toDelete->prev;
                    // si la lista está vacía, pq quizas tiene un solo elemento, y ahora list->tail = NULL
                    if(list->tail != NULL){
                        list->tail->next = NULL;
                    }
                   
                }
                else{
                    toDelete->prev->next = toDelete->next;
                    toDelete->next->prev = toDelete->prev;
                }
                
                
                free(toDelete);

            }

            else{
                Aux = Aux->next;
            }
            
        }
        
    }


void print_current_events(EventList* list, time_t current_time) {
    Event* current = list->head;
    printf("Eventos actuales (después de eliminar expirados):\n");
    while (current != NULL) {
        printf("Evento en %ld con duración %d\n", current->timestamp, current->duration);
        current = current->next;
    }
}

void destroy_list(EventList* list) {
    Event *Aux; Event *toDelete; 
    Aux = list->head;

    while(Aux != NULL){
        toDelete = Aux;
        Aux = Aux->next;

        free(toDelete);
    }
    free(list);
}
