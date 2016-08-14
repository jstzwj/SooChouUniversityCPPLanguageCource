#pragma once
#ifndef COOP_CLASS
#define COOP_CLASS

#define classbegin(classname) struct classname{
#define classend };

#define PRIVATE_MEMBER_BEGIN typedef struct privatemember{
#define PRIVATE_MEMBER_END }private;

#define PROTECTED_MEMBER_BEGIN typedef struct protectedmember{
#define PROTECTED_MEMBER_END }protected;

#define PUBLIC_MEMBER_BEGIN
#define PUBLIC_MEMBER_END

#define DERIVED(baseclass) baseclass base;

#define function(result,name,...) result (*name)(##__VA_ARGS__);


#endif // !COOP_CLASS
