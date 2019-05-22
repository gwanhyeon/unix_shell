# UNIX PRGORMMING MINI KGH SHELL 

# What kind of Mini Shell function?
```
prompt path = local path
$mv
$cp
$clear
$mkdir
$rmdir
$help
$echo
$date
$pwd
$history 
etc. exevp unix system call command 
프롬프트는 현재 local 서버와 동일하게 한다.
cd [arg]  인자를 지정하지 않으면 홈 디렉토리로 이동한다.
echo [args] 인자를 반향(echo)한다.
exit [n] 종료 상태를 n으로 반환하고, 종료한다.
history  히스토리 목록을 행 번호와 함께 출력한다
pwd 현재 작업 디렉토리를 보여준다. 
mkdir, rmdir 디렉터리 생성 및 삭제
나머지 커맨드 라인execpv 명령어 처리
```

# How does it work?
## $gcc -o "object $file name" myShell.c

```
$mv
$mv unix.c unix_exam.c
->unix.c to unix_exam.c 파일명 변경
->$mv unix.c ..
->이전 디렉터리로 unix.c 값 이동
```

```
$cp
->$cp unix.c unix_exam.c
->unix_c to unix_exam.c 복사
```

```
$mkdir 
->$mkdir dir1 dir2 
```

```
$rmdir 
->$rmdir dir1
```

```
$date
->$date
```

```
$pwd 
->$pwd

```
```
$history
->$hitory
```

```
$help
->$help

```
```
$clear
->clear
터미널의 명령행들 모두 clear
```

```
$exit
$exit
System exit(0)

```
# What is the final result?
> $Unix Mini Shell Program  

# Who made it?
> Created by Gwan-Hyeon Kim
