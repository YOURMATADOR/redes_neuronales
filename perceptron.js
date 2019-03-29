// * creacion de una neurona con auto aprendisaje
let ejemplo = [{ in: [], out: 0 }]

class Neurona {
	constructor(entrenamiento, n) {
		this.entrenamiento = entrenamiento
		this.grad = [0, 0, 0]
	}
	distribucion() {
		while (!this.distribucion.criterio_salida()) {
			// * funcion que determina si aun es necesario determinar errores
			this.entrenamiento.map((i) => {
				console.log(`inputs`)

				this.p = this.propagacion(i.in)
				this.out = this.activacion(this.p)
				if (abs(this.out, i.out) > 0.5) {
					let error = i.out - this.out
					error *= TASA_AP
					this.grad[0] += i.in[0] * error
					this.grad[1] += i.in[1] * error
					this.grad[2] += error
				}
				this.actualiza_w(i)
			})
		}
	}
	
	propagacion() {
		let sum = 0
	}
	activacion(x) {
		let resul = 1.0 / (1 + Math.exp(-1 * x))
		return resul
	}
	error(esperado, real) {
		this.error = esperado - real
		return abs(error) > 0.5
	}
	aprendizaje() {
		this.error *= TAZA_APRENDIXAJE
		G[N] += err;
	}
}

let nueva_neurona = new Neurona([
	{ in: [0, 0], out: 0 },
	{ in: [1, 0], out: 0 },
	{ in: [0, 1], out: 0 },
	{ in: [0, 1], out: 1 }
])
