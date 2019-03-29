// * agrega como 2 parametro la taza de aprendisaje (.01 por defecto) y como tercero la iteracion (10 por defecto)
const p = new Perceptron(x[0].length);

p.fit(x,y);

console.log('Informacion procesada',x)
console.log('0 = Iris-setosa1 = Iris-versicolor',y)

let d = document.createElement('div');

d.innerText = p.predict([5.2,2.1,4.5,1.5]);

document.body.appendChild(d);
