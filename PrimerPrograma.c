#include <pebble.h>
// primero creamos el puntero a la ventana que muestre el pebble, que será pública
Window *window;
//Puntero a los textos en pantalla
TextLayer *text_layer;

// Luego la inicializamos
void init() {
  // Create the Window
  window = window_create();
  //ahora crearemos un texto a partir del 00 y de 144x40 puntos? o lineas? no se todavía
  text_layer = text_layer_create(GRect(0, 0, 144, 40));
  text_layer_set_text(text_layer, "Mi primer programa Pebble!");  //pero esto aún no se ve. 
  //para que se vea, hay que crear un nuevo layer hijo
  layer_add_child(window_get_root_layer(window), 
                    text_layer_get_layer(text_layer));

  // Push to the stack, animated
  window_stack_push(window, true);
}

//antes de terminar, borrar la ventana
void deinit() {
  // Destroy the Window
  window_destroy(window);
}
int main() {
   // Initialize the app
  init();

  // Wait for app events
    app_event_loop();
 // De initialize the app
  text_layer_set_text(text_layer,"Voy a terminar!!\n");
  text_layer_get_layer(text_layer);
   // pause;
  deinit();

  // App finished without error
  return 0;
}
  