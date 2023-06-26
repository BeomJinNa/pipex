## System Calls

1. **fork** (`#include <unistd.h>`)
    - `pid_t fork(void);`
        - Function: 현재 실행 중인 프로세스를 복제해 새로운 프로세스를 생성.

2. **pipe** (`#include <unistd.h>`)
    - `int pipe(int pipefd[2]);`
        - Function: 두 개의 파일 디스크립터를 생성해서 이들을 파이프로 연결. `pipefd[0]`은 읽기용, `pipefd[1]`은 쓰기용.

3. **dup, dup2** (`#include <unistd.h>`)
    - `int dup(int oldfd);`
    - `int dup2(int oldfd, int newfd);`
        - Function: 이미 열려있는 파일 디스크립터를 복제.

4. **execve** (`#include <unistd.h>`)
    - `int execve(const char *filename, char *const argv[], char *const envp[]);`
        - Function: 새로운 프로세스 이미지를 로드하고 실행. `filename`은 실행 파일의 이름, `argv`는 실행 파일의 인자 목록, `envp`는 새 프로세스의 환경 변수 목록.

5. **exit** (`#include <stdlib.h>`)
    - `void exit(int status);`
        - Function: 프로세스 종료하고 모든 자원 반환. `status`는 종료 상태.

6. **wait, waitpid** (`#include <sys/wait.h>`)
    - `pid_t wait(int *status);`
    - `pid_t waitpid(pid_t pid, int *status, int options);`
        - Function: 부모 프로세스가 자식 프로세스 종료를 대기하고 종료 상태를 얻음. `pid`는 대기할 프로세스의 ID, `status`는 프로세스의 종료 상태를 저장할 변수의 주소, `options`는 동작 방식 설정.

7. **access** (`#include <unistd.h>`)
    - `int access(const char *pathname, int mode);`
        - Function: 파일의 접근 권한 확인. `pathname`은 파일 경로, `mode`는 확인할 권한.

8. **unlink** (`#include <unistd.h>`)
    - `int unlink(const char *pathname);`
        - Function: 파일의 이름을 삭제하고, 필요하다면 파일 삭제. `pathname`은 파일 경로.

## Types and Macros

- **pid_t:** (`#include <sys/types.h>`) 프로세스 ID 타입. int 형태.
- **WIFEXITED, WEXITSTATUS:** (`#include <sys/wait.h>`) 종료 상태 정보 추출 매크로. WIFEXITED는 프로세스가 정상적으로 종료했는지 체크, WEXITSTATUS는 프로세스의 종료 상태 반환.
- **F_OK, R_OK, W_OK, X_OK:** (`#include <unistd.h>`) 파일 접근 권한 확인 매크로. F_OK는 파일 존재, R_OK는 읽기 권한, W_OK는 쓰기 권한, X_OK는 실행 권한 확인에 사용.
