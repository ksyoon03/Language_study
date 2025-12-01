function toggleCode() {
    // 제어할 요소들 가져오기
    const codeContainer = document.getElementById('code-container');
    // document.getElementById('code-container'): HTML 문서에서 'code-container' ID를 사용하는 요소 탐색
    const toggleBtn = document.getElementById('toggle-btn');
    // document.getElementById('code-container'): HTML 문서에서 'toggle-btn' ID를 사용하는 요소 탐색
    // const: 찾아낸 요소에 변수명을 붙임

    // 현재 화면에 표시 상태 확인
    if (codeContainer.style.display === 'none') {
        // 안 보이면 -> 보이게 설정
        codeContainer.style.display = 'block'; // 화면에 블록 표시
        toggleBtn.textContent = "코드 숨기기"; // 버튼 글자 변경
    } else {
        // 보이면 -> 안 보이게 설정
        codeContainer.style.display = 'none'; // 화면에서 블록 제거
        toggleBtn.textContent = "코드 보기"; // 버튼 글자 변경
    }
}