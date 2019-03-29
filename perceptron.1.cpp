#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define TASA_APRENDIZAJE 0.01
class Neurona {
  public:
      Neurona(int n) : N(n) {
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
          cout << "act: " << y << ", ";
          return y;
      }
      void setGradientes (float* g){
          G = g;
          error_acc = 0;
          cout << "PESOS: ";
          for (int i = 0; i <= N; i++){
            cout << W[i] << " ";
          }
          cout << endl;
      }
      bool error(float esperado, float real){
          err = esperado - real;
          return abs(err) > 0.5;
      }
      void aprendizaje(float in[]){
          err *= TASA_APRENDIZAJE;
          cout << "G: {";
          for (int i = 0; i < N; i++){
            G[i] += err * in[i];
            cout << G[i] << ", ";
          }
          G[N] += err;
          cout << G[N] << "}";
      }
      void actualiza_W(){
          for (int i = 0; i <= N; i++){
            W[i] -= G[i];
          }
      }

      bool criterio(){ static int x = 0; return x++ > 5; }

  private:
    int N;
    float *W;
    float *G;
    float error_acc;
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
    srand(time(0));
    Neurona N_AND(2);
    int N = sizeof(ts)/sizeof(Ejemplo);

    while (! N_AND.criterio()){
        float grad[3] = {0,0,0};
        N_AND.setGradientes(grad);
        for (int i = 0; i < N; i++){
            cout << "Inputs: (" << ts[i].in[0] << ", "
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





