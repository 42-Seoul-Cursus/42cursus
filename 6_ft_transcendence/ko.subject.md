# ft_transcendence

- [ft\_transcendence](#ft_transcendence)
  - [Essential Points](#essential-points)
  - [Mandatory part](#mandatory-part)
    - [Overview](#overview)
    - [Minimal technical requirement](#minimal-technical-requirement)
    - [Game](#game)
    - [Security concerns](#security-concerns)
  - [Modules](#modules)
    - [Overview](#overview-1)
    - [Web](#web)
    - [User Management](#user-management)
    - [Gameplay and user experience](#gameplay-and-user-experience)
    - [AI-Algo](#ai-algo)
    - [Cybersecurity](#cybersecurity)
    - [Devops](#devops)
    - [Gaming](#gaming)
    - [Graphics](#graphics)
    - [Accessibility](#accessibility)
    - [Server-Side Pong](#server-side-pong)
  - [Bonus part](#bonus-part)


## Essential Points

This project is a complex undertaking, requiring decision-making within the specified constraints. 
You have some flexibility in implementing certain modules, and it is left to your discretion **within the scope of the subject.** All your choices must be justifiable.

이 프로젝트는 지정된 제약 조건 내에서 의사결정을 내려야 하는 복잡한 작업입니다. 
특정 모듈을 구현할 때 어느 정도의 유연성이 있으며, 이는 **주제의 범위 내에서** 귀하의 재량에 맡겨집니다. 모든 선택은 정당해야 합니다.

If you believe it’s necessary to use _nginx_ to set up your website, there’s no issue, but ask yourself first, is it truly necessary? Can I do without it? Similarly, when faced with a library that could assist you, it’s crucial to understand whether it will fulfill your tasks.
You’re not expected to rework uninteresting sub-layers but rather to make the proposed features function.

웹사이트를 설정하는 데 _nginx_ 를 사용해야 한다고 생각한다면 문제될 것은 없지만, 먼저 스스로에게 정말 필요한지 물어보세요. 그것 없이도 할 수 있을까요? 마찬가지로 도움을 줄 수 있는 라이브러리가 있다면 그 라이브러리가 작업을 수행할 수 있는지 여부를 파악하는 것이 중요합니다.
흥미롭지 않은 하위 레이어를 재작업하는 것이 아니라 제안된 기능이 제대로 작동하도록 만드는 것이 중요합니다.

It’s crucial to understand that you’ll encounter decisions where doubts about implementing certain features will arise. Initially, it is **STRONGLY recommended** to comprehend the project requirements thoroughly. Once you’ve grasped what needs to be accomplished, it is necessary to stay within the framework of the project. When we mention an imposed technology, it explicitly means that everything officially related to the requested framework/language is allowed.

특정 기능을 구현하는 데 의문이 생길 수 있는 결정에 직면할 수 있다는 점을 이해하는 것이 중요합니다. 처음에는 프로젝트 요구 사항을 철저히 이해하는 것이 **강력히 권장**됩니다. 달성해야 할 사항을 파악한 후에는 프로젝트의 틀 안에 머무르는 것이 필요합니다. 부과된 기술을 언급할 때는 요청된 프레임워크/언어와 공식적으로 관련된 모든 것이 허용된다는 것을 명시적으로 의미합니다.

However, we emphasize that when you wish to implement a module, all restrictions apply to that module. For instance, if you want to realize the project with the Backend module as specified in the subject, you can no longer use the default language and must adapt your project accordingly. If you still want to create a backend using the default language, it’s also possible, but since you’re not using the requested language/framework, this module will not be considered valid.

그러나 모듈을 구현하고자 할 때는 해당 모듈에 모든 제한 사항이 적용된다는 점을 강조합니다. 예를 들어 주제에 명시된 대로 백엔드 모듈로 프로젝트를 구현하려면 더 이상 기본 언어를 사용할 수 없으며 그에 맞게 프로젝트를 조정해야 합니다. 여전히 기본 언어를 사용하여 백엔드를 만들려는 경우에도 가능하지만 요청된 언어/프레임워크를 사용하지 않으므로 이 모듈은 유효한 것으로 간주되지 않습니다.

Before concluding, it’s important to note that some modules intentionally have strong dependencies on others.

결론을 내리기 전에 일부 모듈은 의도적으로 다른 모듈에 대한 종속성이 강하다는 점에 유의해야 합니다.

Your choices are significant and must be justified during your evaluation. Exercise caution.

여러분의 선택은 중요하며 평가 과정에서 반드시 정당한 근거를 제시해야 합니다. 주의를 기울이세요.

Take the time to contemplate the design of your application with your choices before delving into the code – it’s crucial.

코드를 살펴보기 전에 시간을 들여 애플리케이션의 디자인에 대해 생각해 보는 것이 중요합니다.

Have a fun ! :)


## Mandatory part

This project is about creating a website for the mighty **Pong** contest!

이 프로젝트는 강력한 **퐁** 대회를 위한 웹사이트를 만드는 것입니다!

> [Warning] <br>
> The use of libraries or frameworks or tools to replace your job is strictly prohibited. <br>
> 직무를 대체하기 위해 라이브러리나 프레임워크 또는 도구를 사용하는 것은 엄격히 금지됩니다. <br><br>
> Each part of the subject will explicitly present the authorized third party software you can use. <br>
> 각 주제에서는 사용할 수 있는 승인된 타사 소프트웨어를 명시적으로 제시합니다. <br><br>
> Nevertheless, it is allowed and even recommended to use anything possible to simplify certain actions. <br>
> 그럼에도 불구하고 특정 작업을 단순화하기 위해 가능한 모든 것을 사용하는 것은 허용되며 권장되기도 합니다. <br><br>
>  It is important to note that any tools or resources utilized must be justified. <br>
> 사용하는 도구나 리소스는 반드시 정당한 근거가 있어야 한다는 점에 유의하세요. <br><br>
> Please be aware that simplifying does not equate to completing your work. <br>
> 단순화가 작업 완료와 동일시되는 것은 아니라는 점에 유의하시기 바랍니다.

### Overview

Thanks to your website, users will play Pong with others. You have to provide a nice user interface and real-time multiplayer online games!

웹 사이트 덕분에 사용자들은 다른 사람들과 함께 퐁을 플레이할 수 있습니다. 멋진 사용자 인터페이스와 실시간 멀티플레이어 온라인 게임을 제공해야 합니다!

- Your project needs to adhere to the following guidelines as a minimum requirement, contributing only a small portion to the final grade.
- 프로젝트는 최소한의 요구 사항으로 다음 지침을 준수해야 하며, 최종 성적에 기여하는 부분은 극히 일부에 불과합니다.
- The second part of this subject will offer additional modules that can replace or complete the following rules.
- 이 주제의 두 번째 부분에서는 다음 규칙을 대체하거나 완성할 수 있는 추가 모듈을 제공합니다.

In this Subject, certain words are highlighted in `green`. These represent technology choices that will evolve over time. Pay close attention to the version of the subject.

이 주제에서는 특정 단어가 `녹색`으로 강조 표시되어 있습니다. 이는 시간이 지남에 따라 발전할 기술 선택을 나타냅니다. 주제의 버전을 주의 깊게 살펴보세요.

### Minimal technical requirement

Your project has to comply with the following rules:

프로젝트는 다음 규칙을 준수해야 합니다:

> [Info] <br>
> Again, some of these contraints could be overriden by the choice of specific modules. <br>
> 다시 말하지만, 이러한 제한 사항 중 일부는 특정 모듈을 선택함으로써 재정의할 수 있습니다.

- You are free to develop the site, with or without a backend.
- 백엔드를 포함하거나 포함하지 않고 자유롭게 사이트를 개발할 수 있습니다.
  - If you choose to include a backend, it must be written in pure `Ruby` . However, this requirement can be overridden by the **Framework module**.
  - 백엔드를 포함하기로 선택한 경우 순수 `Ruby`로 작성해야 합니다. 그러나 이 요구 사항은 **프레임워크 모듈**로 재정의할 수 있습니다.
  - If your backend or framework uses a database, you must follow the constraints of the **Database module**.
  - 백엔드 또는 프레임워크가 데이터베이스를 사용하는 경우 **Database module**의 제약 조건을 따라야 합니다.
- The frontend should be developed using pure vanilla `Javascript` . However, this requirement can be altered through the **FrontEnd module**.
- 프론트엔드는 순수 바닐라 `Javascript`를 사용하여 개발해야 합니다. 그러나 이 요구 사항은 **FrontEnd module**을 통해 변경할 수 있습니다.
- Your website must be a [single-page application](https://en.wikipedia.org/wiki/Single-page_application). The user should be able to use the Back and Forward buttons of the browser.
- 웹사이트는 [single-page application](https://en.wikipedia.org/wiki/Single-page_application)이어야 합니다. 사용자가 브라우저의 뒤로 및 앞으로 버튼을 사용할 수 있어야 합니다.
- Your website must be compatible with the latest stable up-to-date version of `Google Chrome`.
- 웹사이트는 안정적인 최신 버전의 `Google Chrome`과 호환되어야 합니다.
- The user should encounter no unhandled errors and no warnings when browsing the website.
- 사용자가 웹사이트를 탐색할 때 처리되지 않은 오류나 경고가 발생하지 않아야 합니다.
- Everything must be launched with a single command line to run an autonomous container provided by `Docker`. Example : `docker-compose up --build`
- `Docker`에서 제공하는 자율 컨테이너를 실행하려면 모든 것이 단일 명령줄로 시작되어야 합니다. 예 : `docker-compose up --build`

> [Warning] <br>
> If your container solution is Docker: <br>
> 컨테이너 솔루션이 Docker인 경우: <br><br>
> When your computers in clusters run under Linux, you will use Docker in rootless mode for security reasons. This comes with 2 sideways: <br>
> 클러스터의 컴퓨터가 Linux에서 실행되는 경우 보안상의 이유로 루트 없는 모드에서 Docker를 사용하게 됩니다. 이에는 2가지 제약 사항이 있습니다:
> - Your Docker runtime files must be located in /goinfre or /sgoinfre.
> - You can’t use so called “bind-mount volumes” between the host and the container if non-root UIDs are used in the container.
> - Docker 런타임 파일은 /goinfre 또는 /sgoinfre에 위치해야 합니다.
> - 컨테이너에서 루트가 아닌 UID를 사용하는 경우 호스트와 컨테이너 간에 소위 "바인드 마운트 볼륨"을 사용할 수 없습니다.
> 
> Depending on the project, your situation and the context, several fallbacks exist: Docker in a VM, rebuild you container after your changes, craft your own docker image with root as unique UID.<br>
>프로젝트, 상황 및 컨텍스트에 따라 몇 가지 대체 방법이 있습니다: 가상 머신에서 도커를 사용하거나, 변경 후 컨테이너를 다시 빌드하거나, 루트를 고유 UID로 사용하여 자체 도커 이미지를 만들 수 있습니다.

### Game

The main purpose of this website is to play Pong versus other players.

이 웹사이트의 주요 목적은 다른 플레이어와 대결하여 퐁을 플레이하는 것입니다.

- Therefore, users must have the ability to participate in a live Pong game against another player directly on the website. Both players will use the same keyboard. The **Remote players module** can enhance this functionality with remote players.
- 플레이어는 다른 플레이어와 대결할 수 있어야 하지만 **tournament**를 제안할 수도 있어야 합니다. 이 토너먼트는 여러 플레이어가 교대로 서로 대결할 수 있는 방식으로 구성됩니다. 토너먼트 구현 방식은 유연하게 결정할 수 있지만, 누가 누구와 대결하는지, 플레이어의 순서는 명확하게 표시되어야 합니다.
- A player must be able to play against another player, but it should also be possible to propose a **tournament**. This tournament will consist of multiple players who can take turns playing against each other. You have flexibility in how you implement the tournament, but it must clearly display who is playing against whom and the order of the players.
- 따라서 사용자는 웹사이트에서 직접 다른 플레이어와 실시간 탁구 게임에 참여할 수 있어야 합니다. 두 플레이어는 동일한 키보드를 사용하게 됩니다. **Remote players module**은 원격 플레이어를 통해 이 기능을 향상시킬 수 있습니다.
- A **registration system** is required: at the start of a tournament, each player must input their alias name. The aliases will be reset when a new tournament begins. However, this requirement can be modified using the **Standard User Management module**.
- **registration system**이 필요합니다: 토너먼트 시작 시 각 플레이어는 자신의 별칭 이름을 입력해야 합니다. 새로운 토너먼트가 시작되면 별칭은 초기화됩니다. 그러나 이 요건은 **Standard User Management module**을 사용하여 수정할 수 있습니다.
- There must be a **matchmaking system**: the tournament system organize the matchmaking of the participants, and announce the next fight.
- **matchmaking system**이 있어야 합니다: 토너먼트 시스템은 참가자의 매치메이킹을 구성하고 다음 경기를 공지합니다.
- All players must adhere to the same rules, which includes having identical paddle speed. This requirement also applies when using AI; the AI must exhibit the same speed as a regular player.
- 모든 플레이어는 동일한 규칙을 준수해야 하며, 여기에는 동일한 패들 속도가 포함됩니다. 이 요건은 인공지능을 사용할 때도 적용되며, 인공지능은 일반 플레이어와 동일한 속도를 보여야 합니다.
- The game itself must be developed in accordance with the default frontend constraints (as outlined above), or you may choose to utilize the **FrontEnd module**, or you have the option to override it with the **Graphics module**. While the visual aesthetics can vary, it must still capture the essence of the **original Pong** (1972).
- 게임 자체는 기본 프론트엔드 제약 조건(위에 설명된 대로)에 따라 개발해야 하며, **FrontEnd module**을 사용하거나 **Graphics module**을 사용하여 이를 재정의할 수 있는 옵션이 있습니다. 시각적 미학은 다양할 수 있지만, **original Pong**(1972)의 본질을 담아내야 합니다.

> [Warning] <br>
> The use of libraries or frameworks or tools to replace your job is strictly prohibited. <br>
> 라이브러리나 프레임워크 또는 도구를 사용하여 사용자의 작업을 대체하는 행위는 작업은 엄격히 금지됩니다. <br><br> 
> Each part of the subject will explicitly present the authorized third party software you can use. <br>
> 주제의 각 부분에서는 사용할 수 있는 승인된 타사 소프트웨어를 명시적으로 제시합니다. <br><br>
> Nevertheless, it is allowed and even recommended to use anything possible to simplify certain actions. <br>
> 그럼에도 불구하고 특정 작업을 단순화하기 위해 특정 작업을 단순화할 수 있습니다. <br><br>
> It is important to note that any tools or resources utilized must be justified. <br>
> 사용하는 도구나 리소스는 반드시 정당한 근거가 있어야 한다는 점에 유의하세요. <br><br>
> Please be aware that simplifying does not equate to completing your work. <br>
> 단순화가 작업의 완성과 동일시되는 것은 아니라는 점에 유의하세요.

### Security concerns

In order to create a basic functional website, here are a few security concerns that you have to tackle:

기본적인 기능을 갖춘 웹사이트를 만들기 위해 해결해야 할 몇 가지 보안 문제가 있습니다:
- Any password stored in your database, if applicable, must be hashed.
- 데이터베이스에 저장된 모든 비밀번호(해당되는 경우)는 해시 처리해야 합니다.
- Your website must be protected against SQL injections/XSS.
- 웹사이트는 SQL 인젝션/XSS로부터 보호되어야 합니다.
- If you have a backend or any other features, it is mandatory to enable an HTTPS connection for all aspects (Utilize wss instead of ws...).
- 백엔드 또는 기타 기능이 있는 경우 모든 측면에서 HTTPS 연결을 활성화해야 합니다(ws... 대신 wss 활용).
- You must implement some form of validation for forms and any user input, either within the base page if no backend is used or on the server side if a backend is employed.
- 백엔드를 사용하지 않는 경우 기본 페이지 내에서, 백엔드를 사용하는 경우 서버 측에서 양식 및 모든 사용자 입력에 대해 어떤 형태로든 유효성 검사를 구현해야 합니다.

> [Warning] <br>
> Please make sure you use a strong password hashing algorithm <br>
> 강력한 비밀번호 해싱 알고리즘을 사용해야 합니다.

> [Warning] <br>
> For obvious security reasons, any credentials, API keys, env variables etc... must be saved locally in a .env file and ignored by git. <br>
> 명백한 보안상의 이유로 모든 자격 증명, API 키, 환경 변수 등은 .env 파일에 로컬로 저장하고 git에서 무시해야 합니다. <br><br>
> Publicly stored credentials will lead you directly to a failure of the project. <br>
> 공개적으로 저장된 자격 증명은 프로젝트의 실패로 직결됩니다.

## Modules

Now that you’ve accomplished 25% of the project, congratulations!

이제 프로젝트의 25%를 달성하셨으니 축하드립니다!

With a functional basic website in place, the next step is to choose modules for further improvement.

기능적인 기본 웹사이트를 구축했다면 다음 단계는 추가 개선을 위한 모듈을 선택하는 것입니다.

To attain 100% project completion, a minimum of **7 major modules is required**. It’s crucial to carefully review each module as it may necessitate modifications to your baseline website. Therefore, we strongly recommend reading this entire subject thoroughly.

100% 프로젝트 완료를 달성하려면 최소 **7개의 major modules이 필요합니다**. 기본 웹사이트를 수정해야 할 수도 있으므로 각 모듈을 신중하게 검토하는 것이 중요합니다. 따라서 이 주제 전체를 꼼꼼히 읽어보실 것을 강력히 권장합니다.

> [Warning] <br>
> The use of libraries or frameworks or tools to replace your job is strictly prohibited. <br>
> 업무를 대체하기 위한 라이브러리나 프레임워크 또는 도구의 사용은 엄격히 금지됩니다. <br><br>
> Each part of the subject will explicitly present the authorized third party software you can use. <br>
> 각 항목의 각 부분에는 사용할 수 있는 공인 타사 소프트웨어가 명시적으로 제시되어 있습니다. <br><br>
> Nevertheless, it is allowed and even recommended to use anything possible to simplify certain actions. <br>
> 그럼에도 불구하고 특정 작업을 단순화하기 위해 가능한 모든 것을 사용하는 것은 허용되며 권장되기도 합니다. <br><br>
>  It is important to note that any tools or resources utilized must be justified. <br>
> 사용하는 도구나 리소스는 반드시 정당한 근거가 있어야 한다는 점에 유의하세요. <br><br>
> Please be aware that simplifying does not equate to completing your work. <br>
> 단순화가 작업 완료와 동일하지 않다는 점에 유의하세요. <br><br>
> Two Minor Modules are equivalent to one Major Module. <br>
> 두 개의 마이너 모듈은 하나의 메이저 모듈과 동일합니다.


### Overview

- __Web__
  - [ ] **Major module**: Use a Framework as backend.
  - [ ] *Minor module*: Use a front-end framework or toolkit.
  - [ ] *Minor module*: Use a database for the backend.
  - [ ] **Major module**: Store the score of a tournament in the Blockchain.
- User Management
  - [ ] **Major module**: Standard user management, authentication, users across tournaments.
  - [ ] **Major module**: Implementing a remote authentication.
Gameplay and user experience
  - [ ] **Major module**: Remote players
  - [ ] **Major module**: Multi-players (more than 2 in the same game).
  - [ ] **Major module**: Add Another Game with User History and Matchmaking.
  - [ ] *Minor module*: Game Customization Options.
  - [ ] **Major module**: Live chat.
- AI-Algo
  - [ ] **Major module**: Introduce an AI Opponent.
  - [ ] *Minor module*: User and Game Stats Dashboards
- Cybersecurity
  - [ ] **Major module**: Implement WAF/ModSecurity with Hardened Configuration
and HashiCorp Vault for Secrets Management.
  - [ ] *Minor module*: GDPR Compliance Options with User Anonymization, Local Data Management, and Account Deletion.
  - [ ] **Major module**: Implement Two-Factor Authentication (2FA) and JWT.
- Devops
  - [ ] **Major module**: Infrastructure Setup for Log Management.
  - [ ] *Minor module*: Monitoring system.
  - [ ] **Major module**: Designing the Backend as Microservices.
- Graphics
  - [ ] **Major module**: Use of advanced 3D techniques.
- Accessibility
  - [ ] *Minor module*: Support on all devices.
  - [ ] *Minor module*: Expanding Browser Compatibility.
  - [ ] *Minor module*: Multiple language supports.
  - [ ] *Minor module*: Add accessibility for Visually Impaired Users.
  - [ ] *Minor module*: Server-Side Rendering (SSR) Integration.
- Server-Side Pong
  - [ ] **Major module**: Replacing Basic Pong with Server-Side Pong and Implementing an API.
  - [ ] **Major module**: Enabling Pong Gameplay via CLI against Web Users with API Integration.

### Web

These modules enable the integration of advanced web features into your Pong game.

이러한 모듈은 Pong 게임에 고급 웹 기능을 통합할 수 있도록 합니다.

- **Major module**: Use a Framework as backend. <br>
  In this major module, you are required to utilize a specific web framework for your backend development, and that framework is `Django`.<br>
  이 주요 모듈에서는 백엔드 개발을 위해 특정 웹 프레임워크를 사용해야 하며, 그 프레임워크는 `Django`입니다.
  > [Info] <br>
  > You can create a backend without using the constraints of this module by using the default language/framework. <br>
  > 기본 언어/프레임워크를 사용하여 이 모듈의 제약 조건을 사용하지 않고 백엔드를 만들 수 있습니다. <br><br>
  > However, this module will only be valid if you use the associated constraints. <br>
  > 그러나 이 모듈은 관련 제약 조건을 사용하는 경우에만 유효합니다.
- *Minor module*: Use a front-end framework or toolkit. <br>
  Your frontend development will utilize the `Bootstrap toolkit`. <br>
  프론트엔드 개발은 `Bootstrap toolkit`을 사용할 것입니다.
  > [Info] <br>
  > You can create a front-end without using the constraints of this module by using the default language/framework. <br>
  > 기본 언어/프레임워크를 사용하여 이 모듈의 제약 조건을 사용하지 않고 프론트엔드를 만들 수 있습니다. <br><br>
  >  However, this module will only be valid if you use the associated constraints. <br>
  > 그러나 이 모듈은 관련 제약 조건을 사용하는 경우에만 유효합니다.
- *Minor module*: Use a database for the backend and more. <br>
  The designated database for all DB instances in your project is `PostgreSQL`. This choice guarantees data consistency and compatibility across all project components and may be a prerequisite for other modules, such as the backend Framework module. <br>
  프로젝트의 모든 DB 인스턴스에 대해 지정된 데이터베이스는 `PostgreSQL`입니다. 이 선택은 모든 프로젝트 구성 요소에서 데이터 일관성과 호환성을 보장하며 백엔드 프레임워크 모듈과 같은 다른 모듈의 전제 조건이 될 수 있습니다.
- **Major module**: Store the score of a tournament in the Blockchain. <br>
  This Major module focuses on implementing a feature within the Ponwebsite to store tournament scores securely on a blockchain. It iessential to clarify that fo development and testing purposes, wwill utilize a testing blockchain environment. The chosen blockchaifor this implementation is `Ethereum` , and `Solidity` will be thprogramming language used for smart contract development. <br>
  이 주요 모듈은 토너먼트 점수를 블록체인에 안전하게 저장하는 기능을 폰 웹사이트 내에 구현하는 데 중점을 둡니다. 개발 및 테스트 목적으로 테스트 블록체인 환경을 활용할 것임을 명확히 하는 것이 중요합니다. 이 구현을 위해 선택한 블록체인은 `Ethereum`이며, 스마트 컨트랙트 개발에 사용되는 프로그래밍 언어는 `Solidity`가 될 것입니다.
    - Blockchain Integration: The primary goal of this module is to seamlessly integrate blockchain technology, specifically `Ethereum` , into the Pong website. This integration ensures the secure and immutable storage of tournament scores, providing players with a transparent and tamper-proof record of their gaming achievements.
    - 블록체인 통합: 이 모듈의 주요 목표는 블록체인 기술, 특히 `Ethereum`을 Pong 웹사이트에 원활하게 통합하는 것입니다. 이 통합은 토너먼트 점수를 안전하고 변경할 수 없는 방식으로 저장하여 플레이어에게 게임 성과에 대한 투명하고 변조 불가능한 기록을 제공합니다.
    - `Solidity` Smart Contracts: To interact with the blockchain, we will develop `Solidity` smart contracts. These contracts will be responsible for recording, managing, and retrieving tournament scores.
    - `Solidity` 스마트 컨트랙트: 블록체인과 상호 작용하기 위해 `Solidity` 스마트 컨트랙트를 개발할 것입니다. 이 계약은 토너먼트 점수를 기록, 관리 및 검색하는 역할을 담당할 것입니다.
    - Testing Blockchain: As mentioned earlier, a testing blockchain will be employed for development and testing purposes. This ensures that all blockchain-related functionalities are thoroughly validated without any risks associated with a live blockchain
    - 테스트 블록체인: 앞서 언급했듯이 테스트 블록체인은 개발 및 테스트 목적으로 사용됩니다. 이를 통해 모든 블록체인 관련 기능을 라이브 블록체인과 관련된 위험 없이 철저하게 검증할 수 있습니다.
    - Interoperability: This module may have dependencies on other modules, particularly the Backend Framework module. Integrating blockchain functionality might necessitate adjustments in the backend to accommodate interactions with the blockchain.
    - 상호운용성: 이 모듈은 다른 모듈, 특히 백엔드 프레임워크 모듈에 종속성을 가질 수 있습니다. 블록체인 기능을 통합하려면 블록체인과의 상호 작용을 수용하기 위해 백엔드를 조정해야 할 수도 있습니다.

By implementing this module, we aim to enhance the Pong website by introducing a blockchain-based score storage system. Users will benefit from the added layer of security and transparency, ensuring the integrity of their gaming scores. The module emphasizes the use of a testing blockchain environment to minimize risks associated with blockchain development

이 모듈을 구현함으로써 저희는 블록체인 기반 점수 저장 시스템을 도입하여 Pong 웹사이트를 개선하고자 합니다. 사용자는 보안과 투명성이 강화되어 게임 점수의 무결성을 보장하는 이점을 누릴 수 있습니다. 이 모듈은 블록체인 개발과 관련된 위험을 최소화하기 위해 테스트 블록체인 환경의 사용을 강조합니다.

### User Management

### Gameplay and user experience

### AI-Algo

### Cybersecurity

### Devops

### Gaming

### Graphics

### Accessibility

### Server-Side Pong

## Bonus part

For this project, the bonus section is designed to be straightforward. You are required to include more modules.

- Five points will be awarded for each **minor module**.
- Ten points will be awarded for each **major module**.

> [Warning] <br> 
> The bonus part will only be assessed if the mandatory part is PERFECT.
> Perfect means the mandatory part has been integrally done and works without malfunctioning. 
> If you have not passed ALL the mandatory requirements, your bonus part will not be evaluated at all.
