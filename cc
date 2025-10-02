<!DOCTYPE html>
<html lang="zh-CN">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>水柜天团 - THE UNION OF TANK</title>
    <link href="https://fonts.googleapis.com/css2?family=Ma+Shan+Zheng&display=swap" rel="stylesheet">
    <style>
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
        }
        
        body {
            font-family: 'Arial', sans-serif;
            background: linear-gradient(135deg, #0c1a2d 0%, #1a3a5f 100%);
            color: #e0e0e0;
            line-height: 1.6;
            min-height: 100vh;
            padding: 20px;
            transition: margin-left 0.3s ease;
        }
        
        /* 侧边栏样式 */
        .sidebar {
            height: 100%;
            width: 0;
            position: fixed;
            z-index: 1000;
            top: 0;
            left: 0;
            background: linear-gradient(to bottom, #0c1a2d 0%, #1a3a5f 100%);
            overflow-x: hidden;
            transition: 0.3s;
            padding-top: 60px;
            box-shadow: 2px 0 10px rgba(0, 0, 0, 0.5);
        }
        
        .sidebar.open {
            width: 250px;
        }
        
        .sidebar a {
            padding: 15px 25px;
            text-decoration: none;
            font-size: 1.2rem;
            color: #87cefa;
            display: block;
            transition: 0.2s;
            border-bottom: 1px solid rgba(42, 93, 132, 0.3);
        }
        
        .sidebar a:hover {
            color: #1e90ff;
            background-color: rgba(30, 55, 85, 0.5);
            padding-left: 30px;
        }
        
        .close-btn {
            position: absolute;
            top: 10px;
            right: 25px;
            font-size: 2rem;
            color: #87cefa;
            background: none;
            border: none;
            cursor: pointer;
        }
        
        /* 汉堡菜单按钮 */
        .menu-btn {
            position: fixed;
            left: 20px;
            top: 20px;
            z-index: 999;
            background: rgba(30, 55, 85, 0.7);
            color: #87cefa;
            border: none;
            border-radius: 5px;
            padding: 10px 15px;
            cursor: pointer;
            font-size: 1.5rem;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.3);
            transition: background 0.3s;
        }
        
        .menu-btn:hover {
            background: rgba(30, 55, 85, 1);
        }
        
        /* 语言选择器 */
        .language-selector {
            position: fixed;
            top: 20px;
            right: 20px;
            z-index: 1000;
        }
        
        .language-btn {
            background: rgba(30, 55, 85, 0.7);
            color: #87cefa;
            border: none;
            border-radius: 5px;
            padding: 10px 15px;
            cursor: pointer;
            font-size: 1rem;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.3);
            transition: all 0.3s;
        }
        
        .language-btn:hover {
            background: rgba(30, 55, 85, 1);
        }
        
        .language-dropdown {
            display: none;
            position: absolute;
            top: 100%;
            right: 0;
            background: rgba(18, 35, 55, 0.95);
            border-radius: 5px;
            box-shadow: 0 5px 15px rgba(0, 0, 0, 0.3);
            width: 150px;
            z-index: 1001;
            margin-top: 5px;
            overflow: hidden;
        }
        
        .language-dropdown.open {
            display: block;
        }
        
        .language-option {
            padding: 12px 15px;
            color: #87cefa;
            cursor: pointer;
            transition: background 0.2s;
            border-bottom: 1px solid rgba(42, 93, 132, 0.3);
        }
        
        .language-option:last-child {
            border-bottom: none;
        }
        
        .language-option:hover {
            background: rgba(30, 55, 85, 0.7);
        }
        
        /* 当侧边栏打开时，主体内容向右移动 */
        body.sidebar-open {
            margin-left: 250px;
        }
        
        .container {
            max-width: 1200px;
            margin: 0 auto;
            padding: 20px;
            transition: margin-left 0.3s ease;
        }
        
        /* 头部样式 */
        header {
            display: flex;
            align-items: center;
            margin-bottom: 40px;
            position: relative;
            padding: 20px 0;
        }
        
        .logo-container {
            position: relative;
            width: 300px;
            height: 200px;
            margin-right: 30px;
            flex-shrink: 0;
        }
        
        .logo-image {
            width: 100%;
            height: 100%;
            object-fit: cover;
            border-radius: 10px;
            box-shadow: 0 5px 15px rgba(0, 0, 0, 0.5);
            position: relative;
            z-index: 2;
        }
        
        .gradient-overlay {
            position: absolute;
            right: -10px;
            bottom: -10px;
            width: 100%;
            height: 100%;
            background: linear-gradient(to right, rgba(12, 26, 45, 0.8) 0%, transparent 30%), 
                        linear-gradient(to bottom, rgba(12, 26, 45, 0.8) 0%, transparent 30%);
            z-index: 1;
            border-radius: 10px;
        }
        
        .title-container {
            text-align: right;
            flex-grow: 1;
        }
        
        .chinese-title {
            font-family: 'Ma Shan Zheng', cursive, sans-serif;
            font-size: 4rem;
            color: #1e90ff;
            text-shadow: 3px 3px 5px rgba(0, 0, 0, 0.7);
            margin-bottom: 10px;
            letter-spacing: 5px;
        }
        
        .english-title {
            font-size: 1.8rem;
            color: #87cefa;
            text-shadow: 2px 2px 4px rgba(0, 0, 0, 0.5);
            letter-spacing: 3px;
        }
        
        /* 主要内容样式 */
        .main-content {
            display: grid;
            grid-template-columns: 1fr 1fr;
            gap: 30px;
            margin-bottom: 40px;
        }
        
        .about-section, .shiwu-gongshi {
            background: rgba(18, 35, 55, 0.7);
            padding: 25px;
            border-radius: 10px;
            box-shadow: 0 5px 15px rgba(0, 0, 0, 0.3);
        }
        
        .section-title {
            font-size: 2rem;
            color: #87ceeb;
            margin-bottom: 20px;
            padding-bottom: 10px;
            border-bottom: 2px solid #2a5d84;
        }
        
        /* 事务卡片样式 */
        .shiwu-grid {
            display: grid;
            grid-template-columns: 1fr 1fr;
            gap: 20px;
        }
        
        .shiwu-card {
            background: rgba(30, 55, 85, 0.5);
            padding: 15px;
            border-radius: 8px;
            text-align: center;
        }
        
        .shiwu-name {
            font-size: 1.3rem;
            color: #87cefa;
            margin: 10px 0 5px;
        }
        
        /* 页脚样式 */
        footer {
            text-align: center;
            padding: 20px;
            margin-top: 40px;
            border-top: 1px solid #2a5d84;
            color: #87ceeb;
        }
        
        /* 阿拉伯语样式 */
        body[dir="rtl"] .title-container {
            text-align: left;
        }
        
        body[dir="rtl"] .sidebar {
            left: auto;
            right: 0;
        }
        
        body[dir="rtl"] .sidebar a:hover {
            padding-left: 15px;
            padding-right: 30px;
        }
        
        body[dir="rtl"] .close-btn {
            right: auto;
            left: 25px;
        }
        
        body[dir="rtl"] .menu-btn {
            left: auto;
            right: 20px;
        }
        
        body[dir="rtl"] .language-selector {
            right: auto;
            left: 20px;
        }
        
        body[dir="rtl"] .language-dropdown {
            right: auto;
            left: 0;
        }
        
        body[dir="rtl"] .gradient-overlay {
            right: auto;
            left: -10px;
            background: linear-gradient(to left, rgba(12, 26, 45, 0.8) 0%, transparent 30%), 
                        linear-gradient(to bottom, rgba(12, 26, 45, 0.8) 0%, transparent 30%);
        }
        
        /* 响应式设计 */
        @media (max-width: 900px) {
            .main-content {
                grid-template-columns: 1fr;
            }
            
            header {
                flex-direction: column;
                text-align: center;
            }
            
            .logo-container {
                margin-right: 0;
                margin-bottom: 20px;
            }
            
            .title-container {
                text-align: center;
            }
            
            .chinese-title {
                font-size: 3rem;
            }
            
            body.sidebar-open {
                margin-left: 0;
            }
            
            body[dir="rtl"] .title-container {
                text-align: center;
            }
        }
        
        @media (max-width: 600px) {
            .shiwu-grid {
                grid-template-columns: 1fr;
            }
            
            .chinese-title {
                font-size: 2.5rem;
            }
            
            .english-title {
                font-size: 1.5rem;
            }
            
            .sidebar.open {
                width: 200px;
            }
            
            .language-btn {
                padding: 8px 12px;
                font-size: 0.9rem;
            }
            
            .language-dropdown {
                width: 130px;
            }
        }
    </style>
</head>
<body>
    <!-- 汉堡菜单按钮 -->
    <button class="menu-btn" onclick="toggleSidebar()">☰</button>
    
    <!-- 语言选择器 -->
    <div class="language-selector">
        <button class="language-btn" onclick="toggleLanguageDropdown()">🌐 选择语言</button>
        <div id="languageDropdown" class="language-dropdown">
            <div class="language-option" onclick="translatePage('zh')">简体中文</div>
            <div class="language-option" onclick="translatePage('zh-TW')">繁體中文</div>
            <div class="language-option" onclick="translatePage('en')">English</div>
            <div class="language-option" onclick="translatePage('ru')">Русский</div>
            <div class="language-option" onclick="translatePage('fr')">Français</div>
            <div class="language-option" onclick="translatePage('ko')">한국어</div>
            <div class="language-option" onclick="translatePage('ja')">日本語</div>
            <div class="language-option" onclick="translatePage('ar')">العربية</div>
            <div class="language-option" onclick="translatePage('vi')">Tiếng Việt</div>
        </div>
    </div>
    
    <!-- 侧边栏 -->
    <div id="sidebar" class="sidebar">
        <button class="close-btn" onclick="toggleSidebar()">&times;</button>
        <a href="http://97hs.cn" target="_blank">钟灵毓秀</a>
        <a href="https://en4xnev1.html2web.com/" target="_blank">企鹅报时</a>
        <a href="https://www.baidu.com" target="_blank">百度</a>
        <a href="https://chat.deepseek.com/" target="_blank">Deepseek</a>
        <a href="https://www.doubao.com/chat/" target="_blank">豆包</a>
        <a href="https://web.xml.wiki/" target="_blank">Anywhere</a>
        <a href="https://www.bmcx.com/" target="_blank">便民查询网</a>
        <a href="https://www.bilibili.com/" target="_blank">B站</a>
        <a href="https://fanyi.baidu.com/mtpe-individual/transText#/" target="_blank">百度翻译</a>
        <a href="https://snapany.com/zh/bilibili#google_vignette" target="_blank">B站视频下载</a>
        <a href="https://www.moqukeji.com/" target="_blank">墨趣书法</a>       
        <a href="https://www.wenshushu.cn/" target="_blank">文叔叔</a>
        <a href="https://cloud.lilywhite.cc/" target="_blank">莉莉云</a>
    </div>
    
    <div class="container">
        <header>
            <div class="logo-container">
                <img src="https://mmbiz.qpic.cn/sz_mmbiz_jpg/qjzoSCaTUoyHsl6AnElYbBUKWuNSEyJibXibIYxMe7R9kXCKY61lwhMIY3naSQZwSjIGzTWa8TgDGJYslsPWhQ4w/0?wxfrom=12&wx_fmt=jpg&tp=webp&usePicPrefetch=1&watermark=1" alt="水柜天团" class="logo-image">
                <div class="gradient-overlay"></div>
            </div>
            <div class="title-container">
                <h1 class="chinese-title">水柜天团</h1>
                <p class="english-title">THE UNION OF TANK</p>
            </div>
        </header>
        
        <main class="main-content">
            <section class="shiwu-gongshi">
                <h2 class="section-title">事务公示</h2>
                <div class="shiwu-grid">
                    <div class="shiwu-card">
                        <h3 class="shiwu-name">水柜天团线上服务暂停通知（2025-8-30）</h3>
                        <p>为了进一步提升服务质量，优化用户体验，水柜天团将于2025年8月31日起对网站进行全面深度维护。维护期间，线上服务将暂停……（点进查看）</p>
                    </div>
                    <div class="shiwu-card">
                        <h3 class="shiwu-name">水柜天团关于加强保密工作的通告（2025-8-27）</h3>
                        <p>近期，我水柜天团遭遇了外部人员潜入并导致机密信息泄露的严重事件。此次泄密事件给我们带来了极大的损失和潜在风险，严重威胁到天团的安全与稳定发展……（点进查看）</p>
                    </div>
                </div>
            </section>
            
            <section class="about-section">
                <h2 class="section-title">关于我们</h2>
                <p>水柜天团是由一群水柜文化和历史的爱好者组成的团体。我们致力于研究、保护和推广隐含的历史文化，让更多人了解那些藏在那冰山一角之下的秘密。</p>
                <p>···</p>
                <p>水柜天团的前身是北京小组，成立于公元2024年8月2日，我们已发展成为一个拥有四名核心成员的著名社区，为水柜文化爱好者提供交流平台。</p>
                <p>···</p>
                <p>我们的使命是："为中国人民谋幸福，为中华民族谋复兴"。</p>
                <p>···</p>
            </section>
            
        </main>
        
        <footer>
            <p>© 2025 水柜天团 - THE UNION OF TANK. 保留所有权利。</p>
            <p>联系我们 | 关注我们: 微信公众号@新水柜</p>
        </footer>
    </div>

    <script>
        // 保存原始文本
        const originalTexts = new Map();
        
        // 初始化保存原始文本
        function initOriginalTexts() {
            const elementsToTranslate = document.querySelectorAll('h2, h3, p, a, footer p');
            elementsToTranslate.forEach(element => {
                if (element.classList.contains('chinese-title')) return;
                originalTexts.set(element, element.textContent);
            });
        }
        
        // 侧边栏功能
        function toggleSidebar() {
            const sidebar = document.getElementById('sidebar');
            const body = document.body;
            
            sidebar.classList.toggle('open');
            body.classList.toggle('sidebar-open');
        }
        
        // 语言下拉菜单功能
        function toggleLanguageDropdown() {
            const dropdown = document.getElementById('languageDropdown');
            dropdown.classList.toggle('open');
        }
        
        // 点击页面其他区域关闭下拉菜单
        document.addEventListener('click', function(event) {
            const sidebar = document.getElementById('sidebar');
            const menuBtn = document.querySelector('.menu-btn');
            const languageDropdown = document.getElementById('languageDropdown');
            const languageBtn = document.querySelector('.language-btn');
            
            // 关闭侧边栏
            if (!sidebar.contains(event.target) && event.target !== menuBtn && sidebar.classList.contains('open')) {
                sidebar.classList.remove('open');
                document.body.classList.remove('sidebar-open');
            }
            
            // 关闭语言下拉菜单
            if (!languageDropdown.contains(event.target) && event.target !== languageBtn && languageDropdown.classList.contains('open')) {
                languageDropdown.classList.remove('open');
            }
        });
        
        // 翻译功能
        function translatePage(lang) {
            // 关闭语言下拉菜单
            document.getElementById('languageDropdown').classList.remove('open');
            
            // 确保原始文本已保存
            if (originalTexts.size === 0) {
                initOriginalTexts();
            }
            
            // 模拟翻译 - 实际应用中可替换为真实翻译API
            const translations = {
                'zh': {
                    '事务公示': '事务公示',
                    '水柜天团线上服务暂停通知（2025-8-30）': '水柜天团线上服务暂停通知（2025-8-30）',
                    '为了进一步提升服务质量，优化用户体验，水柜天团将于2025年8月31日起对网站进行全面深度维护。维护期间，线上服务将暂停……（点进查看）':'为了进一步提升服务质量，优化用户体验，水柜天团将于2025年8月31日起对网站进行全面深度维护。维护期间，线上服务将暂停……（点进查看）',
                    '水柜天团关于加强保密工作的通告（2025-8-27）': '水柜天团关于加强保密工作的通告（2025-8-27）',
                    '近期，我水柜天团遭遇了外部人员潜入并导致机密信息泄露的严重事件。此次泄密事件给我们带来了极大的损失和潜在风险，严重威胁到天团的安全与稳定发展……（点进查看）': '近期，我水柜天团遭遇了外部人员潜入并导致机密信息泄露的严重事件。此次泄密事件给我们带来了极大的损失和潜在风险，严重威胁到天团的安全与稳定发展……（点进查看）',
                    '关于我们': '关于我们',
                    '水柜天团是由一群水柜文化和历史的爱好者组成的团体。我们致力于研究、保护和推广隐含的历史文化，让更多人了解那些藏在那冰山一角之下的秘密。': '水柜天团是由一群水柜文化和历史的爱好者组成的团体。我们致力于研究、保护和推广隐含的历史文化，让更多人了解那些藏在那冰山一角之下的秘密。',
                    '水柜天团的前身是北京小组，成立于公元2024年8月2日，我们已发展成为一个拥有四名核心成员的著名社区，为水柜文化爱好者提供交流平台。': '水柜天团的前身是北京小组，成立于公元2024年8月2日，我们已发展成为一个拥有四名核心成员的著名社区，为水柜文化爱好者提供交流平台。',
                    '我们的使命是："为中国人民谋幸福，为中华民族谋复兴"。': '我们的使命是："为中国人民谋幸福，为中华民族谋复兴"。',
                    '© 2025 水柜天团 - THE UNION OF TANK. 保留所有权利。': '© 2025 水柜天团 - THE UNION OF TANK. 保留所有权利。',
                    '联系我们 | 关注我们: 微信公众号@新水柜': '联系我们 | 关注我们: 微信公众号@新水柜',
                    '选择语言': '选择语言'
                },
                'zh-TW': {
                    '事务公示': '事務公示',
                    '水柜天团线上服务暂停通知（2025-8-30）': '水櫃天團線上服務暫停通知（2025-8-30）',
                    '为了进一步提升服务质量，优化用户体验，水柜天团将于2025年8月31日起对网站进行全面深度维护。维护期间，线上服务将暂停……（点进查看）':'為了進一步提升服務質量，優化用戶體驗，水櫃天團將於2025年8月31日起對網站進行全面深度維護。維護期間，線上服務將暫停……（點進查看）',
                    '水柜天团关于加强保密工作的通告（2025-8-27）': '水櫃天團關於加強保密工作的通告（2025-8-27）',
                    '近期，我水柜天团遭遇了外部人员潜入并导致机密信息泄露的严重事件。此次泄密事件给我们带来了极大的损失和潜在风险，严重威胁到天团的安全与稳定发展……（点进查看）': '近期，我水櫃天團遭遇了外部人員潛入並導致機密信息洩露的嚴重事件。此次洩密事件給我們帶來了極大的損失和潛在風險，嚴重威脅到天團的安全與穩定發展……（點進查看）',
                    '关于我们': '關於我們',
                    '水柜天团是由一群水柜文化和历史的爱好者组成的团体。我们致力于研究、保护和推广隐含的历史文化，让更多人了解那些藏在那冰山一角之下的秘密。': '水櫃天團是由一群水櫃文化和歷史的愛好者組成的團體。我們致力於研究、保護和推廣隱含的歷史文化，讓更多人了解那些藏在那冰山一角之下的秘密。',
                    '水柜天团的前身是北京小组，成立于公元2024年8月2日，我们已发展成为一个拥有四名核心成员的著名社区，为水柜文化爱好者提供交流平台。': '水櫃天團的前身是北京小組，成立於公元2024年8月2日，我們已發展成為一個擁有四名核心成員的著名社區，為水櫃文化愛好者提供交流平台。',
                    '我们的使命是："为中国人民谋幸福，为中华民族谋复兴"。': '我們的使命是："為中國人民謀幸福，為中華民族謀復興"。',
                    '© 2025 水柜天团 - THE UNION OF TANK. 保留所有权利。': '© 2025 水櫃天團 - THE UNION OF TANK. 保留所有權利。',
                    '联系我们 | 关注我们: 微信公众号@新水柜': '聯繫我們 | 關注我們: 微信公眾號@新水櫃',
                    '选择语言': '選擇語言'
                },
                'en': {
                    '事务公示': 'Announcements',
                    '水柜天团线上服务暂停通知（2025-8-30）': 'The Union of Tank Online Service Suspension Notice（2025-8-30）',
                    '为了进一步提升服务质量，优化用户体验，水柜天团将于2025年8月31日起对网站进行全面深度维护。维护期间，线上服务将暂停……（点进查看）':'To further enhance service quality and optimize user experience, The Union of Tank will undergo comprehensive deep maintenance starting August 31, 2025. During the maintenance period, online services will be suspended... (Click to view)',
                    '水柜天团关于加强保密工作的通告（2025-8-27）': 'Notice on Strengthening Confidentiality Work (2025-8-27)',
                    '近期，我水柜天团遭遇了外部人员潜入并导致机密信息泄露的严重事件。此次泄密事件给我们带来了极大的损失和潜在风险，严重威胁到天团的安全与稳定发展……（点进查看）': 'Recently, our The Union of Tank encountered a serious incident where external personnel infiltrated and caused leakage of confidential information. This leak has brought us great losses and potential risks, seriously threatening the security and stable development of the Union...(Click to view)',
                    '关于我们': 'About Us',
                    '水柜天团是由一群水柜文化和历史的爱好者组成的团体。我们致力于研究、保护和推广隐含的历史文化，让更多人了解那些藏在那冰山一角之下的秘密。': 'The Union of Tank is a group formed by enthusiasts of tank culture and history. We are dedicated to researching, protecting, and promoting the hidden historical culture, allowing more people to understand the secrets beneath the tip of the iceberg.',
                    '水柜天团的前身是北京小组，成立于公元2024年8月2日，我们已发展成为一个拥有四名核心成员的著名社区，为水柜文化爱好者提供交流平台。': 'The predecessor of The Union of Tank was the Beijing Group, established on August 2, 2024. We have developed into a famous community with four core members, providing a communication platform for tank culture enthusiasts.',
                    '我们的使命是："为中国人民谋幸福，为中华民族谋复兴"。': 'Our mission is: "To seek happiness for the Chinese people and rejuvenation for the Chinese nation."',
                    '© 2025 水柜天团 - THE UNION OF TANK. 保留所有权利。': '© 2025 The Union of Tank - THE UNION OF TANK. All rights reserved.',
                    '联系我们 | 关注我们: 微信公众号@新水柜': 'Contact Us | Follow Us: WeChat Official Account @新水柜',
                    '选择语言': 'Select Language'
                },
                'ru': {
                    '事务公示': 'Объявления',
                    '水柜天团线上服务暂停通知（2025-8-30）': 'Уведомление о приостановке онлайн-сервисов "Союза Танков"（2025-8-30）',
                    '为了进一步提升服务质量，优化用户体验，水柜天团将于2025年8月31日起对网站进行全面深度维护。维护期间，线上服务将暂停……（点进查看）':'Для дальнейшего повышения качества обслуживания и оптимизации пользовательского опыта, "Союз Танков" проведет полное глубокое техническое обслуживание с 31 августа 2025 года. В течение периода обслуживания онлайн-сервисы будут приостановлены... (Нажмите для просмотра)',
                    '水柜天团关于加强保密工作的通告（2025-8-27）': 'Уведомление об усилении режима секретности (2025-8-27)',
                    '近期，我水柜天团遭遇了外部人员潜入并导致机密信息泄露的严重事件。此次泄密事件给我们带来了极大的损失和潜在风险，严重威胁到天团的安全与稳定发展……（点进查看）': 'Недавно наш Танковый Союз столкнулся с серьезным инцидентом, когда внешний персонал проник и вызвал утечку confidentialной информации. Эта утечка нанесла нам огромные потери и потенциальные риски, серьезно угрожая безопасности и стабильному развитию Союза...(Нажмите для просмотра)',
                    '关于我们': 'О нас',
                    '水柜天团是由一群水柜文化和历史的爱好者组成的团体。我们致力于研究、保护和推广隐含的历史文化，让更多人了解那些藏在那冰山一角之下的秘密。': 'Танковый Союз - это группа, созданная энтузиастами танковой культуры и истории. Мы занимаемся изучением, защитой и продвижением скрытой исторической культуры, позволяя большему количеству людей понять секреты, скрытые под tipом айсберга.',
                    '水柜天团的前身是北京小组，成立于公元2024年8月2日，我们已发展成为一个拥有四名核心成员的著名社区，为水柜文化爱好者提供交流平台。': 'Предшественником Танкового Союза была Пекинская Группа, созданная 2 августа 2024 года. Мы превратились в известное сообщество с четырьмя основными участниками, предоставляя платформу для общения энтузиастам танковой культуры.',
                    '我们的使命是："为中国人民谋幸福，为中华民族谋复兴"。': 'Наша миссия: "Стремиться к счастью китайского народа и возрождению китайской нации."',
                    '© 2025 水柜天团 - THE UNION OF TANK. 保留所有权利。': '© 2025 Танковый Союз - THE UNION OF TANK. Все права защищены.',
                    '联系我们 | 关注我们: 微信公众号@新水柜': 'Свяжитесь с нами | Подпишитесь на нас: Официальный аккаунт WeChat @新水柜',
                    '选择语言': 'Выбрать язык'
                },
                'fr': {
                    '事务公示': 'Annonces',
                    '水柜天团线上服务暂停通知（2025-8-30）': 'Avis de suspension des services en ligne de l Union des Chars（2025-8-30）',
                    '为了进一步提升服务质量，优化用户体验，水柜天团将于2025年8月31日起对网站进行全面深度维护。维护期间，线上服务将暂停……（点进查看）':'Afin d\'améliorer davantage la qualité du service и d\'optimiser l\'expérience utilisateur, l\'Union des Chars procédera à une maintenance approfondie complète à partir du 31 août 2025. Pendant la période de maintenance, les services en ligne seront suspendus... (Cliquez pour voir)',
                    '水柜天团关于加强保密工作的通告（2025-8-27）': 'Avis sur le renforcement des travaux de confidentialité (2025-8-27)',
                    '近期，我水柜天团遭遇了外部人员潜入并导致机密信息泄露的严重事件。此次泄密事件给我们带来了极大的损失和潜在风险，严重威胁到天团的安全与稳定发展……（点进查看）': 'Récemment, notre Union des Chars a subi un incident grave où du personnel externe s\'est infiltré и вызвал утечку confidentialной информации. Cette fuite nous a causé des pertes importantes et des risques potentiels, menaçant gravement la sécurité и le développement stable de l\'Union...(Cliquez pour voir)',
                    '关于我们': 'À propos de nous',
                    '水柜天团是由一群水柜文化和历史的爱好者组成的团体。我们致力于研究、保护和推广隐含的历史文化，让更多人了解那些藏在那冰山一角之下的秘密。': 'L\'Union des Chars est un groupe formé par des passionnés de la culture et de l\'histoire des chars. Nous nous consacrons à la recherche, à la protection et à la promotion de la culture historique cachée, permettant à plus de gens de comprendre les secrets cachés sous la pointe de l\'iceberg.',
                    '水柜天团的前身是北京小组，成立于公元2024年8月2日，我们已发展成为一个拥有四名核心成员的著名社区，为水柜文化爱好者提供交流平台。': 'Le prédécesseur de l\'Union des Chars était le Groupe de Pékin, créé le 2 août 2024. Nous sommes devenus une communauté renommée avec quatre membres principaux, offrant une plateforme de communication aux passionnés de la culture des chars.',
                    '我们的使命是："为中国人民谋幸福，为中华民族谋复兴"。': 'Notre mission est : "Rechercher le bonheur pour le peuple chinois et la revitalisation de la nation chinoise."',
                    '© 2025 水柜天团 - THE UNION OF TANK. 保留所有权利。': '© 2025 Union des Chars - THE UNION OF TANK. Tous droits réservés.',
                    '联系我们 | 关注我们: 微信公众号@新水柜': 'Contactez-nous | Suivez-nous: Compte officiel WeChat @新水柜',
                    '选择语言': 'Choisir la langue'
                },
                'ko': {
                    '事务公示': '공지사항',
                    '水柜天团线上服务暂停通知（2025-8-30）': '더 유니온 오브 탱크 온라인 서비스 중단 안내（2025-8-30）',
                    '为了进一步提升服务质量，优化用户体验，水柜天团将于2025年8月31日起对网站进行全面深度维护。维护期间，线上服务将暂停……（点进查看）':'서비스 품질 향상과 사용자 경험 최적화를 위해 더 유니온 오브 탱크는 2025년 8월 31일부터 전면적인 심층 유지보수를 실시합니다. 유지보수 기간 동안 온라인 서비스가 중단됩니다... (자세히 보기)',
                    '水柜天团关于加强保密工作的通告（2025-8-27）': '기밀 작업 강화에 관한 공지 (2025-8-27)',
                    '近期，我水柜天团遭遇了外部人员潜入并导致机密信息泄露的严重事件。此次泄密事件给我们带来了极大的损失和潜在风险，严重威胁到天团的安全与稳定发展……（点进查看）': '최근 우리 탱크 연합은 외부 인원이 침투하여 기밀 정보가 유출되는 심각한 사건을 겪었습니다. 이 유출 사건은 우리에게 엄청난 손실과 잠재적 위험을 가져왔으며, 연합의 안전과 안정적인 발전을 심각하게 위협하고 있습니다...(자세히 보기)',
                    '关于我们': '회사 소개',
                    '水柜天团是由一群水柜文化和历史的爱好者组成的团体。我们致力于研究、保护和推广隐含的历史文化，让更多人了解那些藏在那冰山一角之下的秘密。': '탱크 연합은 탱크 문화와 역사를 좋아하는 애호가들로 구성된 그룹입니다. 우리는 숨겨진 역사 문화를 연구, 보호 및 홍보하여 더 많은 사람들이 빙산의 일각 아래 숨겨진 비밀을 이해할 수 있도록 노력하고 있습니다.',
                    '水柜天团的前身是北京小组，成立于公元2024年8月2日，我们已发展成为一个拥有四名核心成员的著名社区，为水柜文化爱好者提供交流平台。': '탱크 연합의 전신은 2024년 8월 2일에 설립된 베이징 그룹입니다. 우리는 4명의 핵심 멤버를 가진 유명 커뮤니티로 발전하여 탱크 문화 애호가들을 위한 교류 플랫폼을 제공하고 있습니다.',
                    '我们的使命是："为中国人民谋幸福，为中华民族谋复兴"。': '우리의 사명은: "중국 국민의 행복과 중화 민족의 부흥을追求하는 것입니다."',
                    '© 2025 水柜天团 - THE UNION OF TANK. 保留所有权利。': '© 2025 탱크 연합 - THE UNION OF TANK. 모든 권리 보유.',
                    '联系我们 | 关注我们: 微信公众号@新水柜': '문의하기 | 팔로우하기: WeChat 공식 계정 @新水柜',
                    '选择语言': '언어 선택'
                },
                'ja': {
                    '事务公示': 'お知らせ',
                    '水柜天团线上服务暂停通知（2025-8-30）': 'ザ・ユニオン・オブ・タンクオンラインサービス停止のお知らせ（2025-8-30）',
                    '为了进一步提升服务质量，优化用户体验，水柜天团将于2025年8月31日起对网站进行全面深度维护。维护期间，线上服务将暂停……（点进查看）':'サービス品質のさらなる向上とユーザーエクスペリエンスの最優化のため、ザ・ユニオン・オブ・タンクは2025年8월 31日から全面的な深メンテナンスを実施します。メンテナンス期間中、オンラインサービスは停止されます…(詳細を見る)',
                    '水柜天团关于加强保密工作的通告（2025-8-27）': '機密保持作業の強化に関するお知らせ (2025-8-27)',
                    '近期，我水柜天团遭遇了外部人员潜入并导致机密信息泄露的严重事件。此次泄密事件给我们带来了极大的损失和潜在风险，严重威胁到天团的安全与稳定发展……（点进查看）': '最近、私たちのタンク連合は、外部の人間が潜入し機密情報が漏洩する深刻な事件に遭遇しました。この情報漏洩は私たちに多大な損失と潜在的なリスクをもたらし、連合の安全と安定な発展を深刻に脅かしています...(詳細を見る)',
                    '关于我们': '私たちについて',
                    '水柜天团是由一群水柜文化和历史的爱好者组成的团体。我们致力于研究、保护和推广隐含的历史文化，让更多人了解那些藏在那冰山一角之下的秘密。': 'タンク連合は、タンクの文化と歴史を愛好する人々によって結成されたグループです。私たちは隠された歴史文化を研究、保護、普及することに尽力し、より多くの人々が氷山の一角の下に隠された秘密を理解できるようにしています。',
                    '水柜天团的前身是北京小组，成立于公元2024年8月2日，我们已发展成为一个拥有四名核心成员的著名社区，为水柜文化爱好者提供交流平台。': 'タンク連合の前身は、2024年8月2日に設立された北京グループです。私たちは4名のコアメンバーを擁する有名なコミュニティに成長し、タンク文化愛好家のための交流プラットフォームを提供しています.',
                    '我们的使命是："为中国人民谋幸福，为中华民族谋复兴"。': '私たちの使命は、「中国人民の幸福と中華民族の復興を追求すること」です。',
                    '© 2025 水柜天团 - THE UNION OF TANK. 保留所有权利。': '© 2025 タンク連合 - THE UNION OF TANK. 無断複写・転載を禁じます。',
                    '联系我们 | 关注我们: 微信公众号@新水柜': 'お問い合わせ | フォローはこちら: WeChat公式アカウント@新水柜',
                    '选择语言': '言語を選択'
                },
                'ar': {
                    '事务公示': 'إعلانات',
                    '水柜天团线上服务暂停通知（2025-8-30）': 'إشعار تعليق خدمات اتحاد الدبابات عبر الإنترنت (2025-8-30)',
                    '为了进一步提升服务质量，优化用户体验，水柜天团将于2025年8月31日起对网站进行全面深度维护。维护期间，线上服务将暂停……（点进查看）':'لتعزيز جودة الخدمة وتحسين تجربة المستخدم، سيخضع اتحاد الدبابات للصيانة الشاملة العميقة ابتداءً من 31 أغسطس 2025. خلال فترة الصيانة، سيتم تعليق الخدمات عبر الإنترنت... (انقر للعرض)',
                    '水柜天团关于加强保密工作的通告（2025-8-27）': 'إشعار بشأن تعزيز أعمال السرية (2025-8-27)',
                    '近期，我水柜天团遭遇了外部人员潜入并导致机密信息泄露的严重事件。此次泄密事件给我们带来了极大的损失和潜在风险，严重威胁到天团的安全与稳定发展……（点进查看）': 'مؤخرًا، تعرض اتحاد الدبابات الخاص بنا لحادث خطير حيث تسلل أفراد خارجيون وتسببوا في تسريب معلومات سرية. هذا التسريب تسبب لنا في خسائر فادحة ومخاطر محتملة، مما يهدد بشدة أمن وتطور الاتحاد المستقر...(انقر للعرض)',
                    '关于我们': 'من نحن',
                    '水柜天团是由一群水柜文化和历史的爱好者组成的团体。我们致力于研究、保护和推广隐含的历史文化，让更多人了解那些藏在那冰山一角之下的秘密。': 'اتحاد الدبابات هو مجموعة شكلها عشاق ثقافة الدبابات وتاريخها. نحن ملتزمون ببحث وحماية وتعزيز الثقافة التاريخية المخفية، مما يسمح للمزيد من الناس بفهم الأسرار المخبأة تحت غطاء الجبل الجليدي.',
                    '水柜天团的前身是北京小组，成立于公元2024年8月2日，我们已发展成为一个拥有四名核心成员的著名社区，为水柜文化爱好者提供交流平台。': 'سلف اتحاد الدبابات كان مجموعة بكين، التي تأسست في 2 أغسطس 2024. لقد تطورنا إلى مجتمع مشهور بأربعة أعضاء أساسيين، نقدم منصة تواصل لعشاق ثقافة الدبابات.',
                    '我们的使命是："为中国人民谋幸福，为中华民族谋复兴"。': 'مهمتنا هي: "السعي لتحقيق السعادة للشعب الصيني وإحياء الأمة الصينية".',
                    '© 2025 水柜天团 - THE UNION OF TANK. 保留所有权利。': '© 2025 اتحاد الدبابات - THE UNION OF TANK. جميع الحقوق محفوظة.',
                    '联系我们 | 关注我们: 微信公众号@新水柜': 'اتصل بنا | تابعنا: حساب WeChat الرسمي @新水柜',
                    '选择语言': 'اختر اللغة'
                },
                'vi': {
                    '事务公示': 'Thông báo',
                    '水柜天团线上服务暂停通知（2025-8-30）': 'Thông báo tạm dừng dịch vụ trực tuyến của Liên minh Xe tăng (2025-8-30)',
                    '为了进一步提升服务质量，优化用户体验，水柜天团将于2025年8月31日起对网站进行全面深度维护。维护期间，线上服务将暂停……（点进查看）':'Để nâng cao hơn nữa chất lượng dịch vụ và tối ưu hóa trải nghiệm người dùng, Liên minh Xe tăng sẽ tiến hành bảo trì toàn diện và sâu rộng từ ngày 31 tháng 8 năm 2025. Trong thời gian bảo trì, dịch vụ trực tuyến sẽ tạm dừng... (Nhấn để xem)',
                    '水柜天团关于加强保密工作的通告（2025-8-27）': 'Thông báo về tăng cường công tác bảo mật (2025-8-27)',
                    '近期，我水柜天团遭遇了外部人员潜入并导致机密信息泄露的严重事件。此次泄密事件给我们带来了极大的损失和潜在风险，严重威胁到天团的安全与稳定发展……（点进查看）': 'Gần đây, Liên minh Xe tăng của chúng tôi đã gặp phải sự cố nghiêm trọng khi có người bên ngoài xâm nhập và gây rò rỉ thông tin mật. Sự cố rò rỉ này đã gây thiệt hại lớn và rủi ro tiềm ẩn, đe dọa nghiêm trọng đến an ninh và sự phát triển ổn định của liên minh...(Nhấn để xem)',
                    '关于我们': 'Về chúng tôi',
                    '水柜天团是由一群水柜文化和历史的爱好者组成的团体。我们致力于研究、保护和推广隐含的历史文化，让更多人了解那些藏在那冰山一角之下的秘密。': 'Liên minh Xe tăng là một nhóm được thành lập bởi những người đam mê văn hóa và lịch sử xe tăng. Chúng tôi dành riêng cho việc nghiên cứu, bảo vệ và quảng bá văn hóa lịch sử ẩn giấu, cho phép nhiều người hiểu được những bí mật ẩn dưới phần nổi của tảng băng chìm.',
                    '水柜天团的前身是北京小组，成立于公元2024年8月2日，我们已发展成为一个拥有四名核心成员的著名社区，为水柜文化爱好者提供交流平台。': 'Tiền thân của Liên minh Xe tăng là Nhóm Bắc Kinh, được thành lập vào ngày 2 tháng 8 năm 2024. Chúng tôi đã phát triển thành một cộng đồng nổi tiếng với bốn thành viên cốt lõi, cung cấp nền tảng giao lưu cho những người đam mê văn hóa xe tăng.',
                    '我们的使命是："为中国人民谋幸福，为中华民族谋复兴"。': 'Sứ mệnh của chúng tôi là: "Mưu cầu hạnh phúc cho nhân dân Trung Hoa và sự phục hưng của dân tộc Trung Hoa".',
                    '© 2025 水柜天团 - THE UNION OF TANK. 保留所有权利。': '© 2025 Liên minh Xe tăng - THE UNION OF TANK. Tất cả các quyền được bảo lưu.',
                    '联系我们 | 关注我们: 微信公众号@新水柜': 'Liên hệ chúng tôi | Theo dõi chúng tôi: Tài khoản WeChat chính thức @Tank mới',
                    '选择语言': 'Chọn ngôn ngữ'
                }
            };
            
            // 获取所有需要翻译的元素
            const elementsToTranslate = document.querySelectorAll('h2, h3, p, a, footer p');
            
            elementsToTranslate.forEach(element => {
                // 跳过"水柜天团"标题
                if (element.classList.contains('chinese-title')) return;
                
                // 获取原始文本
                const originalText = originalTexts.get(element);
                
                if (translations[lang] && translations[lang][originalText]) {
                    element.textContent = translations[lang][originalText];
                }
            });
            
            // 更新按钮文本
            const languageBtn = document.querySelector('.language-btn');
            const languageTexts = {
                'zh': '选择语言',
                'zh-TW': '選擇語言',
                'en': 'Select Language',
                'ru': 'Выбрать язык',
                'fr': 'Choisir la langue',
                'ar': 'اختر اللغة',
                'ko': '언어 선택',
                'ja': '言語を選択',
                'vi': 'Chọn ngôn ngữ'
            };
            
            if (languageTexts[lang]) {
                languageBtn.innerHTML = `🌐 ${languageTexts[lang]}`;
            }
            
            // 处理阿拉伯语的RTL布局
            if (lang === 'ar') {
                document.body.setAttribute('dir', 'rtl');
            } else {
                document.body.removeAttribute('dir');
            }
        }
        
        // 初始化保存原始文本
        document.addEventListener('DOMContentLoaded', initOriginalTexts);
    </script>
</body>
</html>
