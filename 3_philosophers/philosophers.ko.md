# **Philosophers**

##### I never thought philosophy would be so deadly

 철학이 이렇게 치명적인 줄은 생각치도 못했지.


##### _Summary : In this project, you will learn the basics of threading a process. You will see how to create threads and you will discover mutexes._

 요약: 이번 프로젝트에서, 여러분은 프로세스 스레딩의 기본과 스레드를 만드는 방법을 익힐 것입니다. 또한 뮤텍스가 무엇인지도 알아낼 수 있겠지요.


##### _Version : 10_
 버전 : 10

<br>

| Chapter | Contents                                         | page |
| :-----: | :----------------------------------------------- | :--: |
|    1    | [**Introduction**](#Chapter-1)                   |  2   |
|    2    | [**Common Instructions**](#Chapter-2)            |  3   |
|    3    | [**Overview**](#Chapter-3)                       |  5   |
|    4    | [**Global rules**](#Chapter-4)                   |  6   |
|    5    | [**Mandatory part**](#Chapter-5)                 |  8   |
|    6    | [**Bonus part**](#Chapter-6)                     |  9   |
|    7    | [**Submission and peer-evaluation**](#Chapter-7) |  10  |

<br>

# **Chapter 1**

## **Introduction**

##### _Philosophy (from Greek, philosophia, iterally "love of wisdom") is the study of general and fundamental questions about existence, knowledge, values, reason, mind, and language. Such questions are often posed as problems to be studied or resolves. The term was probably coined by Pythagoras (c. 570 - 495 BCE). Philosophical methods include questioning, critical discussion, rational argument, and systematic presentation._

 철학 (Philosophy - 그리스어로 "지혜의 사랑" 이라는 뜻의 Philosophia에서 유래) 은 존재, 지식, 가치, 이성, 감성과 언어에 관한 일반적이고 근본적인 의문점을 다루는 학문이다. 몇몇 의문점들은 종종 연구되거나 해결되어야 할 문제로 취급되기도 한다. 이 용어는 피타고라스 (기원전 570년 - 495년) 에 의해 처음으로 만들어졌다고 추측된다. 철학적 방법에는 질문하기, 비판적인 토론, 이성적인 논쟁, 체계적인 표현이 포함된다.

##### _Classic philosophical question include: Is it possible to know anything and to prove it? What is most real? Philosophers also pose more practical and concrete questions such as: Is ther a best way to live? Is it better to be just or unjust (if one can get away with it)? Do humans have free will?_

 고전적인 철학적 의문점에는 다음과 같은 것들이 포함된다: 세상의 모든 이치를 이해하고 증명하는 것이 가능한가? 무엇이 가장 '진짜' 라고 할 수 있는가? 철학자들은 또한 다음과 같은 실질적이고 구체적인 의문점을 제기하기도 한다: 가장 좋은 삶이란 존재하는가? 정당함과 부정함 중 어느 쪽이 더 나은가 (한 쪽만 선택하여 살 수 있다면)? 인간에게는 자유의지가 있는가?

##### _Historically, "philosophy" encompassed any body of knowledge. From the time of Ancient Greek philosopher Aristotle to the 19th century, "natural philosophy" encompassed astronomy, medicine, and physics. For example, Newton’s 1687 Mathematical Principles of Natural Philosophy later became classified as a book of physics._

 역사적으로, "철학" 은 지식의 모든 부분을 포괄적으로 다루었다. 고대 그리스의 철학자 아리스토텔레스의 시대부터 19세기까지, "자연 철학"은 천문학, 의학, 물리학을 포함했다. 예를 들면, 뉴턴의 1687년 발간된 "자연철학의 수학적 원리" 는 나중에 와서야 물리학 책으로 분류되었다.

##### _In the 19th century, the growth of modern research universities led academic philos- ophy and other disciplines to professionalize and specialize. In the modern era, some investigations that were traditionally part of philosophy became separate academic disciplines, including psychology, sociology, linguistics, and economics._

 19세기 들어 현대 학문을 연구하는 대학들이 성장함에 따라 학문 철학과 여타 학문들을 전문화하고 세부화하였다. 현대에는 철학의 일부분이었던 연구들이 심리학, 사회학, 언어학, 경제학 등 별개의 학문으로 분리되었다.

##### _Other investigations closely related to art, science, politics, or other pursuits remained part of philosophy. For example, is beauty objective or subjective? Are there many scientific methods or just one? Is political utopia a hopeful dream or hopeless fantasy? Major sub-fields of academic philosophy include metaphysics ("concerned with the fundamental nature of reality and being"), epistemology (about the "nature and grounds of knowledge [and]...its limits and validity"), ethics, aesthetics, political philosophy, logic and philosophy of science._

 예술, 과학, 정치 또는 다른 활동들과 밀접하게 관련된 다른 연구들은 그대로 철학의 일부로 남았다. 예를 들어, '아름다움' 은 객관적인가 주관적인가? 특정 문제에 대해서 과학적인 해결법은 단 하나만 존재하는가 또는 여러 개 존재하는가? 정치적 유토피아는 실현될 수 있는 꿈인가 아니면 가망없는 환상인가? 등이 있다. 학문 철학의 주된 하위 분야로는 형이상학 ("현실과 존재의 근본적인 존재에 대한 연구"), 인식론학 ("지식의 본질과 근거, [그리고]... 그 한계와 타당성에 대한 연구"), 윤리학, 미학, 정치 철학, 논리학, 과학 철학 등이 포함된다.

<br>

# **Chapter 2**

## **Common Instructions**

- ##### _Your project must be written in C._

	C언어를 사용하여 프로그램을 작성하여야 합니다.

- ##### _Your project must be written in accordance with the Norm. If you have bonus files/functions, they are included in the norm check and you will receive 0 if there is a norm error inside._

	프로젝트는 Norm 규칙에 맞춰 작성되어야 합니다. 보너스 파일/함수가 존재할 경우, 그 또한 norm 검사에 포함되며 norm error가 있을 시 0점을 받게 됩니다.

- ##### _Your functions should not quit unexpectedly (segmentation fault, bus error, double free, etc) apart from undefined behaviors. If this happens, your project will be considered non functional and will receive a 0 during the evaluation._

	정의되지 않은 동작을 제외하고, 여러분이 작성하신 프로그램이 예기치 않게 중단되어서는 안 됩니다. (예를 들어, segmentation fault, bus error, double free 등) 만약 여러분의 프로그램이 예기치 않게 종료된다면, 제대로 작동하지 않은 것으로 간주되어 평가에서 0점을 받게 됩니다.

- ##### _All heap allocated memory space must be properly freed when necessary. No leaks will be tolerated._

	필요한 경우 heap에 할당된 모든 메모리 공간은 적절하게 해제되어야 합니다. 메모리 누수는 용납될 수 없습니다.

- ##### _If the subject requires it, you must submit a Makefile which will compile your source files to the required output with the flags `-Wall, -Wextra -Werror`, and your Makefile must not relink._

	과제에서 필요한 경우, `-Wall -Wextra -Werror` 플래그를 지정하여 컴파일을 수행하는 Makefile을 제출해야 합니다. Makefile은 relink 되어서는 안 됩니다.

- ##### _Your Makefile must at least contain the rules `$(NAME)`, `all`, `clean`, `fclean` and `re`._

	Makefile은 최소한 `$(NAME)`, `all`, `clean`, `fclean`, `re` 규칙을 포함해야 합니다.

- ##### _To turn in bonuses to your project, you must include a rule bonus to your Makefile, which will add all the various headers, librairies or functions that are forbidden on the main part of the project. Bonuses must be in a different file `_bonus.{c/h}`. Mandatory and bonus part evaluation is done separately._

	프로젝트에 보너스를 제출하려면, Makefile에 보너스 규칙을 포함해야 합니다. 이 보너스 규칙은 프로젝트의 메인 파트에서 금지되었던 모든 다양한 헤더, 라이브러리, 또는 함수들을 추가하여야 합니다. 보너스 과제는 반드시 `_bonus.{c/h}`라는 별도의 파일에 있어야 합니다. 반드시 수행하여야 하는 메인 파트의 평가와 보너스 파트의 평가는 별도로 이뤄집니다.

- ##### _If your project allows you to use your libft, you must copy its sources and its associated Makefile in a libft folder with its associated Makefile. Your project’s Makefile must compile the library by using its Makefile, then compile the project._

	만일 프로젝트에서 여러분의 libft 사용을 허용한다면, 소스들과 관련 Makefile을 함께 루트 폴더 안에 있는 libft 폴더에 복사해야 합니다. 프로젝트의 Makefile은 우선 libft의 Makefile을 사용하여 라이브러리를 컴파일한 다음, 프로젝트를 컴파일해야 합니다.

- ##### _We encourage you to create test programs for your project even though this `work won’t have to be submitted and won’t be graded`. It will give you a chance to easily test your work and your peers’ work. You will find those tests especially useful during your defence. Indeed, during defence, you are free to use your tests and/or the tests of the peer you are evaluating._

	이 과제물을 `제출할 필요가 없고, 채점 받을 필요가 없을`지라도, 저희는 여러분들이 프로젝트를 위한 테스트 프로그램을 만들 것을 권장합니다. 이것은 여러분의 과제물과 동료들의 과제물을 쉽게 테스트할 수 있게 도울 것입니다. 또한, 평가를 진행할 때 이러한 테스트 프로그램들이 특히 유용하다는 사실을 알게 될 것입니다. 평가 시에는 여러분의 테스트 프로그램과 평가 받는 동료의 테스트 프로그램들을 당연히 자유롭게 사용할 수 있습니다.

- ##### _Submit your work to your assigned git repository. Only the work in the git repository will be graded. If Deepthought is assigned to grade your work, it will be done after your peer-evaluations. If an error happens in any section of your work during Deepthought’s grading, the evaluation will stop._

	할당된 git 저장소에 과제물을 제출하세요. 오직 git 저장소에 있는 과제물만 등급이 매겨질 것입니다. Deepthought가 평가하는 과제의 경우엔, 동료평가 이후에 Deepthought가 수행됩니다. 만약 Deepthought 평가 중에 오류가 발생한다면, 그 즉시 평가는 중지될 것입니다.


<br>

# **Chapter 3**

## **Overview**

##### _Here are the things you need to know if you want to succeed this assignment:_
 이 과제를 성공적으로 수행하기 위해 알아야 할 사항은 다음과 같습니다:
 
- ##### _One or more philosophers sit a round table.<br>Ther is a large bowl of spaghetti in the middle of the table._

	 한 명 이상의 철학자들이 원탁에 둘러앉아 있고, 테이블 중앙에는 커다란 스파게티 한 그릇이 놓여 있습니다.

- ##### _The philosophers alternatively `eat`, `think`, or `sleep`.<br>While they are eating, they are not thinking nor sleeping;<br>while thinkg, they are not eating nor sleeping;<br>and, of course, while sleeping, they are not eating nor thinking._
 
	 철학자들은 번갈아가며 `먹기`, `생각하기`, `자기`를 합니다.<br>철학자가 먹고 있을 때에는 생각하거나 자지 않습니다.<br>생각하고 있을 때에는 먹거나 자지 않습니다.<br>물론 자고 있을 때에는 먹거나 생각하지 않습니다.

- ##### _There are also forks on the table. There are `as many forks as philosophers`._

	 탁자 위에는 몇 개의 포크가 올려져 있습니다. 포크의 개수는 `철학자의 수`와 같습니다.

- ##### _Becuase serving and eating spaghetti with only one fork is very inconvenient, a philosopher takes their right and their left forks to eat, one in each hand._

	 한 개의 포크로 스파게티를 먹는 것은 매우 불편하기 때문에, 철학자는 오른손에는 오른쪽 포크를, 왼손에는 왼쪽 포크를 들고 먹습니다.

- ##### _When a philosopher has finished eating, they put their forks back on the table and start sleeping Once awake, they start thinking again. The simulation stops when a philosopher dies of starvation._

	 철학자가 먹기를 마치면, 포크를 탁자 위에 올려놓고 자기를 시작합니다. 자기를 마치면 생각하기를 다시 시작합니다. 시뮬레이션은 철학자가 굶어 죽을 때까지 계속됩니다.

- ##### _Every philosopher needs to eat and should never starve._

	 모든 철학자는 먹어야 하며, 굶어 죽어서는 안됩니다.

- ##### _Philosophers don't speak with each other._

	 철학자들은 서로 대화하지 않습니다.

- ##### _Philosophers don't know if another philospher is about to die._

	 철학자들은 다른 철학자가 죽을 것인지에 대해 알지 못합니다.

- ##### _No need to say that philosophers should avoid dying!_

	 철학자들은 죽는 것을 피해야 합니다!

<br>

# **Chapter 4**

## **Global Rules**

##### _You have to write a program for the mandatory part and another one for the bonus part (if you decide to do the bonus part). They both have to comply with the following rules:_

 필수 부분에 대한 프로그램과 보너스 부분에 대한 프로그램을 작성해야 합니다(보너스 부분을 수행하기로 결정한 경우). 둘 다 다음 규칙을 준수해야 합니다:

- ##### _Global variables are forbidden!_

	 전역 변수는 금지됩니다!

- ##### _Your(s) program(s) should take the following arguments: <br>`number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]`_

	 각 프로그램은 같은 옵션을 가져야 합니다 : 철학자의 수, 철학자의 수명, 밥을 먹는데 걸리는 시간, 잠자는 시간, [각 철학자가 최소한 밥을 먹어야 하는 횟수]

	- ##### _`number_of_philosophers`: The number of philosophers and also the number of forks._

		 철학자의 수 : 철학자의 수와 포크의 수입니다.

	- ##### _`time_to_die`(in milliseconds): If a philosopher didn't start eating `time_to_die` milliseconds the beginning of the simulation, they die._ 

		 철학자의 수명(밀리초 단위) : 철학자가 마지막으로 밥을 먹기 시작한 시점으로부터 `time_to_die` 시간만큼이 지나거나, 프로그램 시작 후 `time_to_die` 시간만큼이 지나도록 식사를 시작하지 않으면 해당 철학자는 사망합니다.

	- ##### _`time_to_eat`(in milliseconds): The time it takes for a philosopher to eat. During that time, they will need to hold two forks._

		 밥을 먹는데 걸리는 시간(밀리초 단위) : 철학자가 밥을 먹는데 걸리는 시간입니다. 해당 시간동안 철학자는 두 개의 포크를 잡고 있어야 합니다.

	- ##### _`time_to_sleep`(in milliseconds): The time the philosopher will spend sleeping._

		 잠자는 시간(밀리초 단위) : 잠을 자는 데 소모되는 시간 입니다.

	- ##### _`number_of_times_each_philosopher_must_eat` (optional argument): If all philosophers have eaten least `number_of_times_each_philosopher_must_eat` times, the simulation stops. If not specified, the simulation stops when a philosopher dies._

		 각 철학자가 최소한 밥을 먹어야 하는 횟수(선택적 인자): 모든 철학자가 `number_of_times_each_philosopher_must_eat` 번 이상 밥을 먹으면 시뮬레이션이 종료됩니다. 지정되지 않은 경우, 철학자가 죽을 때 시뮬레이션이 종료됩니다.

- ##### _Each philosopher has a number ranging frome `1` to `number_of_philosophers`._

	 각 철학자는 `1`부터 `number_of_philosophers`까지의 고유 번호를 가지고 있습니다.

- ##### _Philosopher number 1 sits next to philosopher number `number_of_philosophers`. Any other philosopher number N sits between philsopher number N - 1 and philsopher number N + 1._

	 철학자 번호 1은 철학자 번호 `number_of_philosophers`의 옆에 앉습니다. 그 외에 철학자 번호 N 은 철학자 번호 N - 1 과 철학자 번호 N + 1 사이에 앉습니다.

##### _About the logs of your program:_

 프로그램의 로그에 대해:

- ##### _Any state change of a philosopher must be formatted as follows:_
	 철학자의 상태 변화는 다음과 같이 포맷되어야 합니다:
	- ##### _timestamp_in_ms X has taken a fork_
	- ##### _timestamp_in_ms X is eating_
	- ##### _timestamp_in_ms X is sleeping_
	- ##### _timestamp_in_ms X is thinking_
	- ##### _timestamp_in_ms X died_	 	

	##### _Replace `timestamp_in_ms` with the current timestamp in milliseconds and `X` with the philosopher number._
	 `timestamp_in_ms`를 현재 타임스탬프(밀리초)로 바꾸고 `X`를 철학자 번호로 바꿉니다. 

- ##### _A displayed state message should not be mixed up with another message._
	 
	 철학자의 상태는 다른 철학자들의 상태와 뒤엉키거나 섞인 상태로 출력되면 안 됩니다.

- ##### _A message announcing a philosopher died should be displayed no more than 10 ms after the actual death of the philosopher._

	 철학자의 사망 시점과 이를 출력하기 까지의 틈이 10ms 이상이 되면 안 됩니다.

- ##### _Again, philosophers should avoid dying!_

	 다시 말하지만, 철학자들이 최대한 죽지 않도록 설계해야 합니다!

> ⚠️ <br>
>
> ##### _Your program must not have any `data races`._
>
> 프로그램에 `data races`가 있어서는 안 됩니다.

<br>

# **Chapter 5**

## **Mandatory Part**

| **프로그램 이름** | philo |
| :--------------- | :-------- |
| **제출할 파일** | philo/ 디렉토리 안에 Makefile, *.h, *.c,   |
| **Makefile** | all, clean, fclean, re |
| **인자** | number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat] |
| **사용가능한 외부 함수** | memset, printf, malloc, free, write, usleep, gettimeofday, pthtread_create, pthread_detach, pthread_join, pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock |
| **Libft 사용여부** | No |
| **설명** | Philosophers with threads and mutexes |

##### _The specific rules for the mandatory part are:_

 필수 파트의 규칙은 다음과 같습니다:

- ##### _Each philosopher should be a thread._

	 각 철학자는 스레드로 구현되어 있어야 합니다.

- ##### _There is one fork between each pair of philosophers. Therefore, if there are several philosophers, each philosopher has a fork on their left side and a fork on their right side. If there is only one philosopher, there should be only one fork on the table._

	 두 철학자 사이에 한 개의 포크가 존재하므로, 철학자가 여러명일 경우 각 철학자의 왼쪽과 오른쪽에 포크가 하나씩 존재해야 합니다. 철학자가 한 명일 경우 테이블 위에 포크가 하나만 존재해야 합니다.

- ##### _To prevent philosophers from duplicating forks, you should protect the forks state with a mutex for each of them._

	 철학자가 포크를 복제하는 것을 막기 위해서, 각 포크의 현재 상태를 뮤텍스를 이용하여 보호해주어야 합니다.

<br>

# **Chapter 6**

## **Bonus Part**s

| **프로그램 이름** | philo_bonus |
| :--------------- | :-------- |
| **제출할 파일** | philo_bonus/ 디렉토리 안에 Makefile, *.h, *.c  |
| **Makefile** | all, clean, fclean, re |
| **인자** | number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat] |
| **사용가능한 외부 함수** | memset, printf, malloc, free, write, fork, kill, exit, pthtread_create, pthread_detach, pthread_join, usleep, gettimeofday waitpid, sem_open, sem_close, sem_post, sem_wait, sem_unlink |
| **Libft 사용여부** | No |
| **설명** | Philosophers with processes and semaphores |

##### _The program of the bonus part takes the ame arguments as the mandatory program. It has to comply with the requirements of the Global rules chapter._

 보너스 파트의 프로그램은 필수 파트의 프로그램과 동일한 인자를 받아야 합니다. 또한, Global rules 챕터의 규칙을 준수해야 합니다.

##### _The specific rules for the bonus part are:_

 보너스 파트의 규칙은 다음과 같습니다:

- ##### _All the forks are put int the middle of the table._

	 모든 포크는 테이블 가운데에 있습니다.

- ##### _They have no states in memory but the number of available forks is represented by a semaphore._

	 메모리의 상태는 알 수 없지만, 대신 사용가능한 포크의 수가 세마포어로 표현됩니다.

- ##### _Each philosopher should be a process. But the main process should not be a philosopher._

	 각 철학자는 프로세스로 이루어져 있어야 하고, 메인 프로세스가 철학자가 되어선 안 됩니다.

> ⚠️ <br>
>
> ##### _The bonus part will only be assessed if the mandatory part is PERFECT. Perfect means the mandatory part has been integrally done and works without malfunctioning.  If you have not passed ALL the mandatory requirements, your bonus part will not be evaluated at all._
>
> 

<br>

# **Chapter 7**

## **Submission and peer correction**

##### _Turn in your assignment in your Git repository as usual. Only the work inside your repos- itory will be evaluated during the defense. Don’t hesitate to double check the names of your files to ensure they are correct._

항상 그래왔듯, 여러분의 결과물을 Git 레포지토리에 제출하세요. 레포지토리에 있는 과제물만이 평가될 것입니다. 파일 이름이 올바른지 확인하려면 꼭 한번 더 확인하세요.

##### _Mandatory part directory: philo/_

 필수 파트 디렉토리: philo/

##### _Bonus part directory: philo_bonus/_

 보너스 파트 디렉토리: philo_bonus/
