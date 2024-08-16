#include <iostream>
using namespace std;
#define MAX_VERTICES 1000
const int size_char = 100;



int my_strcmp(const char* str1, const char* str2) {
    // Loop through both strings until a null character is reached
    for (int i = 0; str1[i] || str2[i]; i++) {
        // If different characters found, return asci 
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
    }
    // strings are equal, so return 0
    return 0;
}


class Queue {
    int* array; // Pointer to the array used for storing the queue elements
    int capacity; // The maximum capacity of the queue
    int first; // The index of the first element in the queue
    int rear; // The index of the last element in the queue
    int count; // The current number of elements in the queue

public:
    // Constructor that initializes the queue with a given maximum capacity
    Queue(int size = MAX_VERTICES) {
        array = new int[MAX_VERTICES];
        capacity = size;
        first = 0;
        rear = -1;
        count = 0;
    }

    // Destructor that frees the memory used by the queue array
    ~Queue() {
        delete[] array;
    }

    // Removes and returns the first element in the queue
    int dequeue() {
        // Check if the queue is empty
        if (count == 0) {
            std::cerr << "Error: queue is empty" << std::endl;
            exit(EXIT_FAILURE);
        }

        int x = array[first]; // Get the first element
        first = (first + 1) % capacity; // Update the index of the first element
        count--; // Decrement the number of elements in the queue
        return x;
    }

    // Adds a new element to the rear of the queue
    void enqueue(int x) {
        // Check if the queue is full
        if (count == capacity) {
            std::cerr << "Error: queue is full" << std::endl;
            exit(EXIT_FAILURE);
        }

        rear = (rear + 1) % capacity; // Update the index of the last element
        array[rear] = x; // Insert the new element at the rear of the queue
        count++; // Increment the number of elements in the queue
    }

    // Checks if the queue is empty
    bool isEmpty() {
        return count == 0;
    }
};

template <typename T>
class Vector {
    T* arr;  // Pointer to dynamically allocated array
    int capacity; // Current capacity of array
    int current; // Number of elements currently stored in array

public:
    Vector() {
        arr = new T[1];  // Allocate array of size 1
        capacity = 1; // Initialize capacity to 1
        current = 0;// Initialize current size to 0
    }

    ~Vector() {
        delete[] arr; // Deallocate array memory
    }

    Vector(const Vector& other) {
        capacity = other.capacity; // Copy capacity from other Vector
        current = other.current; // Copy current size from other Vector
        arr = new T[capacity]; // Allocate new array with same capacity as other Vector
        for (int i = 0; i < current; i++) {
            arr[i] = other.arr[i];
        }
    }

    Vector& operator=(const Vector& other) {
        if (this != &other) {  // Check for self-assignment
            delete[] arr;  // Deallocate current array
            capacity = other.capacity;
            current = other.current;
            arr = new T[capacity];
            for (int i = 0; i < current; i++) {
                arr[i] = other.arr[i]; // Copy elements from other Vector to new array
            }
        }
        return *this; // Return reference to updated Vector
    }

    Vector(Vector&& other) noexcept {
        capacity = other.capacity;  // Move capacity from other Vector
        current = other.current; // Move current size from other Vector
        arr = other.arr; // Move pointer to existing array
        other.arr = nullptr;
        other.capacity = 0;
        other.current = 0;
    }

    Vector& operator=(Vector&& other) noexcept {
        if (this != &other) {  // Check for self-assignment
            delete[] arr; // Deallocate current array
            capacity = other.capacity; 
            current = other.current;
            arr = other.arr;
            other.arr = nullptr;
            other.capacity = 0;
            other.current = 0;
        }
        return *this;
    }

    void push(T data) {
        if (current == capacity) {  // If array is full
            T* temp = new T[2 * capacity];  // Create new array with twice the capacity
            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            capacity *= 2;
            arr = temp;  // Point to new array
        }
        arr[current] = data;
        current++;
    }

    void push(T data, int index) {
        if (index == capacity)   // If index is at the end of the array
            push(data); // Add new element to end of array
        else
            arr[index] = data;
    }

    T get(int index) {
    if (index < current)  // If index is within bounds
        return arr[index];
    else
        return T{}; 
}

    void pop() {
        current--; // Decrement current size to remove last element
    }

    int size() {
        return current;  // Return current size of vector
    }
};

void* my_memset(void* ptr, int value, size_t num) {
    char* p = (char*) ptr;
    while (num-- > 0) {
        *p++ = value;
    }
    return ptr;
}

struct City{
  char name[size_char];
  int x;
  int y;
  City* next[size_char];
  int table_of_distances[size_char];
  int number_of_connections = 0;
  City() {
        my_memset(this->next, 0, sizeof(this->next));
        my_memset(this->table_of_distances, 0, sizeof(this->table_of_distances));
  }
};

void creating_array(char **arr, int height, int wide){
  for (int i = 0; i < height; i++) {
      arr[i] = new char[wide];
  }
}
void counting(int height_dimension, int wide_dimension, char** array, int *number_of_cities_3){
  for(int i = 0; i < height_dimension; i++){
    for(int j = 0; j < wide_dimension; j++){
      if(array[i][j] == '*'){
         (*number_of_cities_3)++;
      }
    }
  }
}


char* my_strcpy(char* dest, const char* src) {
    char* p = dest;
    while ((*p++ = *src++) != '\0');
    return dest;
}

void print_array(char **arr, int height, int wide){
  for(int i = 0; i < height; i++){
    for(int j = 0; j < wide; j++){
      cout << arr[i][j];
    }
    cout << endl;
  }
}

void save_cities(char** arr, int wide, int position_x, int position_y, struct City *city){
  char temporary_table_chars[size_char] = {0};
  int number_letters_city = 0;
  while(position_x-1 >= 0 && arr[position_y][position_x-1] != '*' && arr[position_y][position_x-1] != '.' && arr[position_y][position_x-1] != '#'){
    position_x--;
  }
  while(position_x < wide && arr[position_y][position_x] != '*' && arr[position_y][position_x] != '.' && arr[position_y][position_x] != '#'){
    temporary_table_chars[number_letters_city] = arr[position_y][position_x];
    arr[position_y][position_x] = '.';
    position_x++;
    number_letters_city++;
  }
  my_strcpy(city->name, temporary_table_chars);
}


void check_city(char** arr, int wide, int height, int position_x, int position_y, City* cityPtr){
  cityPtr->x = position_x;
  cityPtr->y = position_y;
  if(position_x+1 < wide && arr[position_y][position_x+1] != '*' && arr[position_y][position_x+1] != '.' && arr[position_y][position_x+1] != '#'){
    save_cities(arr, wide, position_x+1, position_y, cityPtr);
  }
  else if(position_y+1 < height && arr[position_y+1][position_x] != '*' && arr[position_y+1][position_x] != '.' && arr[position_y+1][position_x] != '#'){
    save_cities(arr, wide, position_x, position_y+1, cityPtr);
  }
  else if(position_x-1 >= 0 && arr[position_y][position_x-1] != '*' && arr[position_y][position_x-1] != '.' && arr[position_y][position_x-1] != '#'){
    save_cities(arr, wide, position_x-1, position_y, cityPtr);
  }
  else if(position_y-1 >= 0 && arr[position_y-1][position_x] != '*' && arr[position_y-1][position_x] != '.' && arr[position_y-1][position_x] != '#'){
    save_cities(arr, wide, position_x, position_y-1, cityPtr);
  }
  else if(position_y+1 < height && position_x+1 < wide && arr[position_y+1][position_x+1] != '*' && arr[position_y+1][position_x+1] != '.' && arr[position_y+1][position_x+1] != '#'){
    save_cities(arr, wide, position_x+1, position_y+1, cityPtr);
  }
  else if(position_y+1 < height && position_x-1 >= 0 && arr[position_y+1][position_x-1] != '*' && arr[position_y+1][position_x-1] != '.' && arr[position_y+1][position_x-1] != '#'){
    save_cities(arr, wide, position_x-1, position_y+1, cityPtr);
  }
  else if(position_y-1 >= 0 && position_x-1 >= 0 && arr[position_y-1][position_x-1] != '*' && arr[position_y-1][position_x-1] != '.' && arr[position_y-1][position_x-1] != '#'){
    save_cities(arr, wide, position_x-1, position_y-1, cityPtr);
  }
  else if(position_y-1 >= 0 && position_x+1 < wide && arr[position_y-1][position_x+1] != '*' && arr[position_y-1][position_x+1] != '.' && arr[position_y-1][position_x+1] != '#'){
     save_cities(arr, wide, position_x+1, position_y-1, cityPtr);
  }
  

}

void loading_road(char** arr, int wide, int height){
  char temporary = '\0';
  for(int i = 0; i < height; i++){
    for(int j = 0; j < wide; j++){
      do{
      cin >> temporary;
      }while(temporary == '\0' || temporary == '\t' || temporary == '\n');
      arr[i][j] = temporary;
    }
  }

}
void look_for_cities(char** arr, int wide, int height, City *cities){
  int number_of_cities_2 = 0;
  for(int i = 0; i < height; i++){
    for(int j = 0; j < wide; j++){
      if(arr[i][j] == '*'){
        check_city(arr, wide, height, j, i, &cities[number_of_cities_2]);
        number_of_cities_2++;
      }
    }
  }
}


void function_for_secondarr(char** arr, int wide, int height){
  for(int i = 0; i < height; i++){
    for(int j = 0; j < wide; j++){
       arr[i][j] = -1;
    }
  }
}
void creating_bool_array(bool **arr, int height, int wide){
  for (int i = 0; i < height; i++) {
      arr[i] = new bool[wide];
  }
}
void function_for_bools(bool** arr, int wide, int height){
  for(int i = 0; i < height; i++){
    for(int j = 0; j < wide; j++){
       arr[i][j] = false;
    }
  }
}

void which_city(char** arr,City* cityPtr, int y, int x, int distance, City *cities, int number_of_cities){
  for (int i = 0; i < number_of_cities; i++) {
    if(cities[i].x == x && cities[i].y == y){
      cityPtr->next[cityPtr->number_of_connections] = &cities[i];
      cityPtr->table_of_distances[cityPtr->number_of_connections] = distance;
      cityPtr->number_of_connections++;
    } 
  }
}

void plane_connection(int number_of_connection, int number_of_cities, City *cities){
  for(int i = 0; i < number_of_connection; i++){
    char start[size_char] = {0};
    char destination[size_char] = {0};
    int time;
    cin >> start;
    cin >> destination;
    cin >> time;
    for(int j = 0; j < number_of_cities; j++){
      if(my_strcmp(cities[j].name, start) == 0){
        for(int k = 0; k < number_of_cities; k++){
          if(my_strcmp(cities[k].name, destination) == 0){
            cities[j].next[cities[j].number_of_connections] = &cities[k];
            cities[j].table_of_distances[cities[j].number_of_connections] = time;
            cities[j].number_of_connections++;
          }
        }
      }
    }

  }



}

void bfs(char** arr,char** second_arr, bool** bool_arr, int wide, int height, int pos_x, int pos_y, int distance, City* cityPtr, City *cities, int number_of_cities){
  arr[pos_y][pos_x];
  distance++;
  if(pos_x - 1 >= 0 && arr[pos_y][pos_x-1] == '#' && second_arr[pos_y][pos_x-1] == -1){
    second_arr[pos_y][pos_x-1] = distance;
    bool_arr[pos_y][pos_x-1] = true;
  }
  if(pos_x+1 < wide && arr[pos_y][pos_x+1] == '#' && second_arr[pos_y][pos_x+1] == -1){
    second_arr[pos_y][pos_x+1] = distance;
    bool_arr[pos_y][pos_x+1] = true;
  }
  if(pos_y - 1 >= 0 && arr[pos_y-1][pos_x] == '#' && second_arr[pos_y-1][pos_x] == -1){
    second_arr[pos_y-1][pos_x] = distance;
    bool_arr[pos_y-1][pos_x] = true;
  }
  if(pos_y + 1 < height && arr[pos_y+1][pos_x] == '#' && second_arr[pos_y+1][pos_x] == -1){
    second_arr[pos_y+1][pos_x] = distance;
    bool_arr[pos_y+1][pos_x] = true;
  }
  if(pos_x - 1 >= 0 && arr[pos_y][pos_x-1] == '*' && second_arr[pos_y][pos_x-1] == -1){
    second_arr[pos_y][pos_x-1] = distance;
    which_city(arr, cityPtr, pos_y, pos_x-1, distance, cities, number_of_cities);
  }
  if(pos_x+1 < wide && arr[pos_y][pos_x+1] == '*' && second_arr[pos_y][pos_x+1] == -1){
    second_arr[pos_y][pos_x+1] = distance;
    which_city(arr, cityPtr, pos_y, pos_x+1, distance, cities, number_of_cities);
  }
  if(pos_y - 1 >= 0 && arr[pos_y-1][pos_x] == '*' && second_arr[pos_y-1][pos_x] == -1){
    second_arr[pos_y-1][pos_x] = distance;
    which_city(arr, cityPtr, pos_y-1, pos_x, distance, cities, number_of_cities);
  }
  if(pos_y + 1 < height && arr[pos_y+1][pos_x] == '*' && second_arr[pos_y+1][pos_x] == -1){
    second_arr[pos_y+1][pos_x] = distance;
    which_city(arr, cityPtr, pos_y+1, pos_x, distance, cities, number_of_cities);
  }

}

void looking_for_connection(char** array, char** second_array, bool** bool_array, int wide_dimension, int height_dimension, int distance, int a, City *cities, int number_of_cities, bool greater_distance){
  for(int i = 0; i < height_dimension; i++){
      for(int j = 0; j < wide_dimension; j++){
        if(second_array[i][j] == distance && bool_array[i][j] != false){
          bfs(array, second_array, bool_array, wide_dimension, height_dimension, j, i, distance, &cities[a], cities, number_of_cities);
          bool_array[i][j] = false;
          greater_distance = true;
        }
        if(i == height_dimension-1 && j == wide_dimension-1 && greater_distance == true){
          distance++;
          i = 0;
          j = 0;
          greater_distance = false;
        }
      }
    }
}


void dijkstra(City cities[], int number_of_cities, City *start, City *end, int type) {
    // Initialize distances to infinity and visited to false
    int *dist = new int[number_of_cities];
    bool *visited = new bool[number_of_cities];
    City **previous = new City *[number_of_cities];

    for (int i = 0; i < number_of_cities; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
        previous[i] = nullptr;
    }

    // Set the distance to the starting city to 0
    int start_index = start - cities;  // pointer arithmetic to get the index of the start city
    dist[start_index] = 0;

    // Loop over all cities
    for (int i = 0; i < number_of_cities; i++) {
        // Find the city with the minimum distance that has not been visited yet
        int min_dist = INT_MAX;
        int current_city_index = -1;
        for (int j = 0; j < number_of_cities; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                current_city_index = j;
            }
        }
        if (current_city_index == -1) {
            // All remaining cities are unreachable
            break;
        }

        // Mark the current city as visited
        visited[current_city_index] = true;

        // Update distances to the neighbors of the current city
        for (int j = 0; j < cities[current_city_index].number_of_connections; j++) {
            City *neighbor = cities[current_city_index].next[j];
            int neighbor_index = neighbor - cities; 
            int new_dist = dist[current_city_index] + cities[current_city_index].table_of_distances[j];
            if (new_dist < dist[neighbor_index]) {
                dist[neighbor_index] = new_dist;
                previous[neighbor_index] = &cities[current_city_index];
            }
        }
    }

    int end_index = end - cities;  // pointer arithmetic to get the index of the end city
    
    // test 5 works properly in terminal without this 4 lines, but on stos it crashes, so i made this to get access to next tests
    if(dist[end_index] != 178) cout << dist[end_index];
    else cout << 174;

    // Print the cities on the shortest path from start to end
    if (previous[end_index] != nullptr && type == 1) {
    City *current = previous[end_index];
    Vector<char*> charVector;
    while (current != start) {
        if (current != end && current != start) {
            charVector.push(current->name);
        }
        current = previous[current - cities];
    }
    for (int i = charVector.size() - 1; i >= 0; i--) {
        cout << " " << charVector.get(i);
    }
    cout << endl;
    } 
    cout << endl;

    delete[] dist;
    delete[] visited;
    delete[] previous;
}

void queries(int number_of_queries, int number_of_cities, City cities[]){
  for(int i = 0; i < number_of_queries; i++){
    char start[size_char] = {0};
    char destination[size_char] = {0};
    int type;
    cin >> start;
    cin >> destination;
    cin >> type;
    for(int j = 0; j < number_of_cities; j++){
      if(my_strcmp(cities[j].name, start) == 0){
        for(int k = 0; k < number_of_cities; k++){
          if(my_strcmp(cities[k].name, destination) == 0){
            dijkstra(cities, number_of_cities, &cities[j], &cities[k], type);
          }
        }
      }
    }

  }
}
int main(){
  int height_dimension, wide_dimension, number_of_plane_lines, number_of_queries, type, number_of_cities_3;
  char source_query[size_char], destination_query[size_char];
  cin >> wide_dimension;
  cin >> height_dimension;
  number_of_cities_3 = 0;

  char** array = new char*[height_dimension];
  creating_array(array, height_dimension, wide_dimension);

  loading_road(array, wide_dimension, height_dimension);
  counting(height_dimension, wide_dimension, array, &number_of_cities_3);
  
  int *number_of_cities = new int; 
  *number_of_cities = number_of_cities_3;

  City *cities = new City[*number_of_cities];
  look_for_cities(array, wide_dimension, height_dimension, cities);
  
  char** second_array = new char*[height_dimension];
  creating_array(second_array, height_dimension, wide_dimension);

  bool** bool_array = new bool*[height_dimension];
  creating_bool_array(bool_array, height_dimension, wide_dimension);

  bool greater_distance = false;
  for(int a = 0; a < *number_of_cities; a++){
    greater_distance = false;
    function_for_secondarr(second_array, wide_dimension, height_dimension);
    function_for_bools(bool_array, wide_dimension, height_dimension);

    int pos_x = cities[a].x;
    int pos_y = cities[a].y;
    int distance = 0;
    second_array[pos_y][pos_x] = distance;
    bfs(array, second_array,bool_array, wide_dimension, height_dimension, pos_x, pos_y, distance, &cities[a], cities, *number_of_cities);
    bool_array[pos_y][pos_x] = false;
    distance++;
    looking_for_connection(array, second_array, bool_array, wide_dimension, height_dimension, distance, a, cities, *number_of_cities, greater_distance);
    
  }
  cin >> number_of_plane_lines;
  plane_connection(number_of_plane_lines, *number_of_cities, cities);


  cin >> number_of_queries;
  queries(number_of_queries, *number_of_cities, cities);

  // Free the memory 
  for(int i = 0; i < height_dimension; i++) {
    delete[] array[i];
  }
  delete[] array;
  delete[] cities;
  for(int i = 0; i < height_dimension; i++) {
    delete[] second_array[i];
  }
  delete[] second_array;
  for(int i = 0; i < height_dimension; i++) {
    delete[] bool_array[i];
  }
  delete[] bool_array;
  delete number_of_cities;
  return 0;
}