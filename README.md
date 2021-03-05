# Semi-Active-Suspension
Semi Active suspension Controller modeling in half car model

1. half car model(해당 모델을 선정한 이유)

차량 동역학에서 서스펜션 컨트롤러의 성능을 검증하기 위해 자주 사용되는 기존의 2자유도 모델(quater car model)은 하나의 서스펜션을 검증하기위해 사용된다. 4자유도 모델(half car model)은 기존의 2자유도 모델을 확장하여 4자유도(two wheels)를 구성하며 그에 따라 4개의 미분 방정식을 필요로 한다. 확장 됨에 따라 검증할 수 있는 요소도 추가되었다. 2자유도 모델의 경우 wheel의 변위와 sprun mass의 변위만을 해석할 수 있었지만 4자유도에서는 기존의 항목에서 sprung mass(Chassis)의 pitch angle과 추가된 wheel의 변위에 대한 해석이 가능하다. 기존의 2자유도 모델에 비해 다양하게 해석 할 수 있다고 생각하여 half car model을 선정하여 controller의 성능을 검증하기로 했다.

![half_model](https://user-images.githubusercontent.com/79674592/110109504-e73ba180-7df0-11eb-8527-68f398297bbd.jpg)

2. equilibrium of force(방정식)

방정식의 스프링상수(k)와 댐퍼 상수(c)는 다음과 같이 정의할 수 있다.
![상수](https://user-images.githubusercontent.com/79674592/110110283-ee16e400-7df1-11eb-91d1-d36bea8d730a.PNG)

시스템의 4개의 미분 방정식은 두개의 자유도(sprung mass,wheels)에서 도출 할 수 있다. sprung mass에 해당하는 미분방정식은 전륜과 후륜의 서스펜션과 sprung mass의 영향을 받는다. sprung mass의 자유물체도는 아래와 같다.
![chassis_accels](https://user-images.githubusercontent.com/79674592/110110689-8f059f00-7df2-11eb-9b65-bda2947112a2.jpg)
sprung mass에서 2개의 방정식을 도출 할 수 있는데 하나는 수직방향 힘의 해석이고 다른 하나는 모멘트의 해석이다. 먼저 힘의 해석을 보면 위에서 구한 상수값의 분모를 소거시켜주기위해 스프링상수의 경우 수직변위의 차를 곱해주고 뎀퍼상수의 경우 상대속도의 차이를 곱해준다. 이 때 질량 중심점과 휠간의 거리에 의해 발생하는 변위는 전륜의 경우(+), 후륜의 경우(-)를 띄는데(좌변 이항시) 이는 요철을 만났을 때 전륜의 경우 힘이 z방향으로 가해질 것이고 힘의 평형의 법칙에 따라 후륜의 경우 z반대 방향으로 작용하기 때문에 lf(theta)와 lr(theta)의 방향은 반대가 된다. 
두번 째는 모멘트(토크)에 관한 해석이다. 모멘트의 경우 힘과 거리의 곱으로 표현 할 수 있기 때문에 위와 같이 나타낼 수 있다. theta의 경우 아주 작은 크기이므로 sin(theta)를 theta로 근사화 한다.
![wheel_accels](https://user-images.githubusercontent.com/79674592/110113373-5f589600-7df6-11eb-898c-89bc3fbe1df2.jpg)
각각의 휠은 위와 같은 자유물체도에 의해 2개의 미분방정식을 도출할 수 있다. kfs와 cfs가 음수인 이유(좌변 이항시)는 sprung mass가 고정되어 있다고 가정한 경우(강체) 전륜이 요철을 만나면 힘이 반대로 작용(-)하게 된다. 반대로 후륜의 경우 평형의 법칙에 의해(+)로 작용하게 된다.

최종적으로 아래와 같은 4개의 미분방정식을 얻게 된다.
![방정식_최종](https://user-images.githubusercontent.com/79674592/110116172-76998280-7dfa-11eb-9fd6-7338664585c8.png)


