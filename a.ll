; ModuleID = 'main'
source_filename = "main"

@0 = private unnamed_addr constant [11 x i8] c"\0AERROR!!!\0A\00", align 1
@1 = private unnamed_addr constant [13 x i8] c"\0Ano errors!\0A\00", align 1
@2 = private unnamed_addr constant [31 x i8] c"Input the number of elements:\0A\00", align 1
@3 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@4 = private unnamed_addr constant [20 x i8] c"Input %d integers:\0A\00", align 1
@5 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@6 = private unnamed_addr constant [19 x i8] c"QuickSort result:\0A\00", align 1
@7 = private unnamed_addr constant [4 x i8] c"%d \00", align 1

declare i32 @printf(i8*, ...)

declare i32 @scanf(i8*, ...)

declare void* @malloc(i64)

declare void @free(void*)

declare void @put_long(i64)

declare void @put_i(i32)

declare void @put_f(double)

define void @QuickSort(i32* %0, i32 %1, i32 %2) {
QuickSort_entry:
  %Tmp = alloca i32, align 4
  %Mid = alloca i32, align 4
  %j = alloca i32, align 4
  %i = alloca i32, align 4
  %R = alloca i32, align 4
  %L = alloca i32, align 4
  %Arr = alloca i32*, align 8
  store i32* %0, i32** %Arr, align 8
  store i32 %1, i32* %L, align 4
  store i32 %2, i32* %R, align 4
  %3 = load i32, i32* %L, align 4
  store i32 %3, i32* %i, align 4
  %4 = load i32, i32* %R, align 4
  store i32 %4, i32* %j, align 4
  %5 = load i32*, i32** %Arr, align 8
  %6 = load i32, i32* %i, align 4
  %7 = load i32, i32* %j, align 4
  %8 = add i32 %6, %7
  %9 = sdiv i32 %8, 2
  %10 = getelementptr i32, i32* %5, i32 %9
  %11 = load i32, i32* %10, align 4
  store i32 %11, i32* %Mid, align 4
  br label %whl_begin

whl_begin:                                        ; preds = %if-quit, %QuickSort_entry
  %12 = load i32, i32* %i, align 4
  %13 = load i32, i32* %j, align 4
  %14 = icmp sle i32 %12, %13
  br i1 %14, label %whl_body, label %whl_end6

whl_body:                                         ; preds = %whl_begin
  br label %whl_begin1

whl_begin1:                                       ; preds = %whl_body2, %whl_body
  %15 = load i32*, i32** %Arr, align 8
  %16 = load i32, i32* %i, align 4
  %17 = getelementptr i32, i32* %15, i32 %16
  %18 = load i32, i32* %17, align 4
  %19 = load i32, i32* %Mid, align 4
  %20 = icmp slt i32 %18, %19
  br i1 %20, label %whl_body2, label %whl_end

whl_body2:                                        ; preds = %whl_begin1
  %21 = load i32, i32* %i, align 4
  %22 = add i32 %21, 1
  store i32 %22, i32* %i, align 4
  br label %whl_begin1

whl_end:                                          ; preds = %whl_begin1
  br label %whl_begin3

whl_begin3:                                       ; preds = %whl_body4, %whl_end
  %23 = load i32, i32* %Mid, align 4
  %24 = load i32*, i32** %Arr, align 8
  %25 = load i32, i32* %j, align 4
  %26 = getelementptr i32, i32* %24, i32 %25
  %27 = load i32, i32* %26, align 4
  %28 = icmp slt i32 %23, %27
  br i1 %28, label %whl_body4, label %whl_end5

whl_body4:                                        ; preds = %whl_begin3
  %29 = load i32, i32* %j, align 4
  %30 = sub i32 %29, 1
  store i32 %30, i32* %j, align 4
  br label %whl_begin3

whl_end5:                                         ; preds = %whl_begin3
  %31 = load i32, i32* %i, align 4
  %32 = load i32, i32* %j, align 4
  %33 = icmp sle i32 %31, %32
  br i1 %33, label %"if-true:", label %if-false

"if-true:":                                       ; preds = %whl_end5
  %34 = load i32*, i32** %Arr, align 8
  %35 = load i32, i32* %i, align 4
  %36 = getelementptr i32, i32* %34, i32 %35
  %37 = load i32, i32* %36, align 4
  store i32 %37, i32* %Tmp, align 4
  %38 = load i32*, i32** %Arr, align 8
  %39 = load i32, i32* %i, align 4
  %40 = getelementptr i32, i32* %38, i32 %39
  %41 = load i32*, i32** %Arr, align 8
  %42 = load i32, i32* %j, align 4
  %43 = getelementptr i32, i32* %41, i32 %42
  %44 = load i32, i32* %43, align 4
  store i32 %44, i32* %40, align 4
  %45 = load i32, i32* %40, align 4
  %46 = load i32*, i32** %Arr, align 8
  %47 = load i32, i32* %j, align 4
  %48 = getelementptr i32, i32* %46, i32 %47
  %49 = load i32, i32* %Tmp, align 4
  store i32 %49, i32* %48, align 4
  %50 = load i32, i32* %48, align 4
  %51 = load i32, i32* %i, align 4
  %52 = add i32 %51, 1
  store i32 %52, i32* %i, align 4
  %53 = load i32, i32* %j, align 4
  %54 = sub i32 %53, 1
  store i32 %54, i32* %j, align 4
  br label %if-quit

if-false:                                         ; preds = %whl_end5
  br label %if-quit

if-quit:                                          ; preds = %if-false, %"if-true:"
  br label %whl_begin

whl_end6:                                         ; preds = %whl_begin
  %55 = load i32, i32* %L, align 4
  %56 = load i32, i32* %j, align 4
  %57 = icmp slt i32 %55, %56
  br i1 %57, label %"if-true:7", label %if-false8

"if-true:7":                                      ; preds = %whl_end6
  %58 = load i32*, i32** %Arr, align 8
  %59 = load i32, i32* %L, align 4
  %60 = load i32, i32* %j, align 4
  call void @QuickSort(i32* %58, i32 %59, i32 %60)
  br label %if-quit9

if-false8:                                        ; preds = %whl_end6
  br label %if-quit9

if-quit9:                                         ; preds = %if-false8, %"if-true:7"
  %61 = load i32, i32* %i, align 4
  %62 = load i32, i32* %R, align 4
  %63 = icmp slt i32 %61, %62
  br i1 %63, label %"if-true:10", label %if-false11

"if-true:10":                                     ; preds = %if-quit9
  %64 = load i32*, i32** %Arr, align 8
  %65 = load i32, i32* %i, align 4
  %66 = load i32, i32* %R, align 4
  call void @QuickSort(i32* %64, i32 %65, i32 %66)
  br label %if-quit12

if-false11:                                       ; preds = %if-quit9
  br label %if-quit12

if-quit12:                                        ; preds = %if-false11, %"if-true:10"
  ret void
}

define void @check_qsort(i32* %0, i32 %1) {
check_qsort_entry:
  %i = alloca i32, align 4
  %size = alloca i32, align 4
  %arr = alloca i32*, align 8
  store i32* %0, i32** %arr, align 8
  store i32 %1, i32* %size, align 4
  store i32 0, i32* %i, align 4
  br label %for_begin

for_begin:                                        ; preds = %for_update, %check_qsort_entry
  %2 = load i32, i32* %i, align 4
  %3 = load i32, i32* %size, align 4
  %4 = sub i32 %3, 1
  %5 = icmp slt i32 %2, %4
  br i1 %5, label %for_body, label %for_end

for_body:                                         ; preds = %for_begin
  %6 = load i32*, i32** %arr, align 8
  %7 = load i32, i32* %i, align 4
  %8 = getelementptr i32, i32* %6, i32 %7
  %9 = load i32, i32* %8, align 4
  %10 = load i32*, i32** %arr, align 8
  %11 = load i32, i32* %i, align 4
  %12 = add i32 %11, 1
  %13 = getelementptr i32, i32* %10, i32 %12
  %14 = load i32, i32* %13, align 4
  %15 = icmp sgt i32 %9, %14
  br i1 %15, label %"if-true:", label %if-false

"if-true:":                                       ; preds = %for_body
  %16 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([11 x i8], [11 x i8]* @0, i32 0, i32 0))
  ret void

if-false:                                         ; preds = %for_body
  br label %if-quit

if-quit:                                          ; preds = %if-false
  br label %for_update

for_update:                                       ; preds = %if-quit
  %17 = load i32, i32* %i, align 4
  %18 = add i32 %17, 1
  store i32 %18, i32* %i, align 4
  br label %for_begin

for_end:                                          ; preds = %for_begin
  %19 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @1, i32 0, i32 0))
  ret void
}

define i32 @main() {
main_entry:
  %i = alloca i32, align 4
  %Arr = alloca i32*, align 8
  %N = alloca i32, align 4
  %0 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([31 x i8], [31 x i8]* @2, i32 0, i32 0))
  %1 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @3, i32 0, i32 0), i32* %N)
  %2 = load i32, i32* %N, align 4
  %3 = sext i32 %2 to i64
  %4 = mul i64 %3, 4
  %5 = call void* @malloc(i64 %4)
  %6 = bitcast void* %5 to i32*
  store i32* %6, i32** %Arr, align 8
  %7 = load i32*, i32** %Arr, align 8
  %8 = load i32, i32* %N, align 4
  %9 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([20 x i8], [20 x i8]* @4, i32 0, i32 0), i32 %8)
  store i32 0, i32* %i, align 4
  %10 = load i32, i32* %i, align 4
  br label %for_begin

for_begin:                                        ; preds = %for_update, %main_entry
  %11 = load i32, i32* %i, align 4
  %12 = load i32, i32* %N, align 4
  %13 = icmp slt i32 %11, %12
  br i1 %13, label %for_body, label %for_end

for_body:                                         ; preds = %for_begin
  %14 = load i32*, i32** %Arr, align 8
  %15 = load i32, i32* %i, align 4
  %16 = getelementptr i32, i32* %14, i32 %15
  %17 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @5, i32 0, i32 0), i32* %16)
  br label %for_update

for_update:                                       ; preds = %for_body
  %18 = load i32, i32* %i, align 4
  %19 = add i32 %18, 1
  store i32 %19, i32* %i, align 4
  br label %for_begin

for_end:                                          ; preds = %for_begin
  %20 = load i32*, i32** %Arr, align 8
  %21 = load i32, i32* %N, align 4
  %22 = sub i32 %21, 1
  call void @QuickSort(i32* %20, i32 0, i32 %22)
  %23 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([19 x i8], [19 x i8]* @6, i32 0, i32 0))
  store i32 0, i32* %i, align 4
  %24 = load i32, i32* %i, align 4
  br label %for_begin1

for_begin1:                                       ; preds = %for_update3, %for_end
  %25 = load i32, i32* %i, align 4
  %26 = load i32, i32* %N, align 4
  %27 = icmp slt i32 %25, %26
  br i1 %27, label %for_body2, label %for_end4

for_body2:                                        ; preds = %for_begin1
  %28 = load i32*, i32** %Arr, align 8
  %29 = load i32, i32* %i, align 4
  %30 = getelementptr i32, i32* %28, i32 %29
  %31 = load i32, i32* %30, align 4
  %32 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @7, i32 0, i32 0), i32 %31)
  br label %for_update3

for_update3:                                      ; preds = %for_body2
  %33 = load i32, i32* %i, align 4
  %34 = add i32 %33, 1
  store i32 %34, i32* %i, align 4
  br label %for_begin1

for_end4:                                         ; preds = %for_begin1
  %35 = load i32*, i32** %Arr, align 8
  %36 = load i32, i32* %N, align 4
  call void @check_qsort(i32* %35, i32 %36)
  %37 = load i32*, i32** %Arr, align 8
  %38 = bitcast i32* %37 to void*
  call void @free(void* %38)
  ret i32 0
}
No errors.
