#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define TASA_APRENDIZAJE 0.025
class Neurona {
  public:
      Neurona(int n) : N(n), intentos(100), prev_error_acc(0) {
          W = new float[N+1];
          for (int i = 0; i <=N; i++)
            W[i] = 0.01 * ((rand() % 201) -100);
      }
      float prop (float in[]){
          float sum = 0;
          for (int i = 0; i < N; i++)
              sum += in[i] * W[i];
          sum += W[N];
          cout << "prop: " << sum << ", ";
          return sum;
      }
      float act (float x){
          float y =  1.0/(1 + exp(-1 * x));
          cout << "\tact: " << y << ", ";
          return y;
      }
      void setGradientes (float* g){
          G = g;
          prev_error_acc = error_acc;
          error_acc = 0;
          cout << "RND: " << intentos << "   ERROR: " << prev_error_acc
               <<"\tPESOS: ";
          for (int i = 0; i <= N; i++){
            cout << W[i] << " ";
          }
          cout << endl;
      }
      bool error(float esperado, float real){
          err = esperado - real;
          bool same_side = abs(err) < 0.5;
          error_acc += abs(err);
          cout << "\terror: " << err << "  "
               << "acc: " << error_acc << " ";
          return !same_side;
      }
      void aprendizaje(float in[]){
          err *= TASA_APRENDIZAJE;
          cout << "\n\t\tG: {";
          for (int i = 0; i < N; i++){
            G[i] += err * in[i];
            cout << G[i] << ", ";
          }
          G[N] += err;
          cout << G[N] << "}";
      }
      void actualiza_W(){
          for (int i = 0; i <= N; i++){
            W[i] += G[i];
          }
      }

      bool criterio(){
          if (abs(error_acc - prev_error_acc) < 0.00001){
              float x = 0;
              for (int i = 0; i <=N; i++)
                  x += abs(G[i]);
              if (x > 0) // Hay gradientes, pero ya no estan logrando reducir el error
                  cout << "\nATASCADO!!! El error ya no se esta reduciendo.\n";
              else
                  cout << "\nEXITO!!!\n"; //Todos los gradientes son ceros, todos los errores individuales son < 0.5
          }
          else if ((intentos-- == 0)){
              cout << "\nTIMEOUT!!! Has agotado el maximo numero de intentos.\n";
          }
          else
            return false; //El criterio de salida no se ha cumplido

          return true; //Se cumplio alguno de los 3 criterios en la instruccion if-else
      }

  private:
    int N, intentos;
    float *W;
    float *G;
    float error_acc, prev_error_acc;
    float err;
};

struct Ejemplo{
    float in[2]; float out;
};
Ejemplo ts[] = {
 {{0, 0}, 0}, {{1, 0}, 0},  {{0, 1}, 0},  {{1, 1}, 1}
};
int main()
{
    srand(1/*time(0)*/);
    cout.precision(4);
    Neurona N_AND(2);
    int N = sizeof(ts)/sizeof(Ejemplo);

    while (! N_AND.criterio()){
        float grad[3] = {0,0,0};
        N_AND.setGradientes(grad);
        for (int i = 0; i < N; i++){
            cout << "\tInputs: (" << ts[i].in[0] << ", "
                                  << ts[i].in[1] << ") ";
            float out = N_AND.act (N_AND.prop (ts[i].in));
            if (N_AND.error(ts[i].out, out)){
                N_AND.aprendizaje(ts[i].in);
            }
            cout << endl;
        }
        N_AND.actualiza_W();
    }
    return 0;
}





