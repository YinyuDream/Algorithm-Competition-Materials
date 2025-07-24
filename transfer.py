from bs4 import BeautifulSoup
import re
import os

def extract_problem_info(html_file_path):
    """
    从Codeforces HTML文件中提取题目信息
    """
    with open(html_file_path, 'r', encoding='utf-8') as file:
        html_content = file.read()
    
    soup = BeautifulSoup(html_content, 'html.parser')
    
    # 提取题目基本信息
    problem_info = {}
    
    # 题目标题
    title_elem = soup.find('div', class_='title')
    if title_elem:
        problem_info['title'] = title_elem.get_text().strip()
    
    # 时间限制
    time_limit_elem = soup.find('div', class_='time-limit')
    if time_limit_elem:
        time_limit = time_limit_elem.find('div', class_='property-title').find_next_sibling(text=True)
        if time_limit:
            problem_info['time_limit'] = time_limit.strip()
    
    # 内存限制
    memory_limit_elem = soup.find('div', class_='memory-limit')
    if memory_limit_elem:
        memory_limit = memory_limit_elem.find('div', class_='property-title').find_next_sibling(text=True)
        if memory_limit:
            problem_info['memory_limit'] = memory_limit.strip()
    
    # 输入输出格式
    input_elem = soup.find('div', class_='input-file')
    if input_elem:
        problem_info['input'] = input_elem.get_text().replace('input', '').strip()
    
    output_elem = soup.find('div', class_='output-file')
    if output_elem:
        problem_info['output'] = output_elem.get_text().replace('output', '').strip()
    
    # 题目描述
    problem_statement = soup.find('div', class_='problem-statement')
    if problem_statement:
        # 题目内容 (去除header部分)
        header = problem_statement.find('div', class_='header')
        if header:
            header.decompose()
        
        # 提取各个部分
        sections = {}
        
        # 题目描述主体
        desc_div = problem_statement.find('div')
        if desc_div and not desc_div.get('class'):
            sections['description'] = clean_html_content(desc_div)
        
        # 输入说明
        input_spec = problem_statement.find('div', class_='input-specification')
        if input_spec:
            sections['input_specification'] = clean_html_content(input_spec)
        
        # 输出说明
        output_spec = problem_statement.find('div', class_='output-specification')
        if output_spec:
            sections['output_specification'] = clean_html_content(output_spec)
        
        # 样例
        sample_tests = problem_statement.find('div', class_='sample-tests')
        if sample_tests:
            sections['sample_tests'] = extract_sample_tests(sample_tests)
        
        # 注释/说明
        note = problem_statement.find('div', class_='note')
        if note:
            sections['note'] = clean_html_content(note)
        
        problem_info['sections'] = sections
    
    # 提取标签
    tags = []
    tag_boxes = soup.find_all('span', class_='tag-box')
    for tag in tag_boxes:
        tag_text = tag.get_text().strip()
        if tag_text and not tag_text.startswith('*'):  # 排除难度标签
            tags.append(tag_text)
        elif tag_text.startswith('*'):
            problem_info['difficulty'] = tag_text
    
    problem_info['tags'] = tags
    
    return problem_info

def clean_html_content(element):
    """
    清理HTML内容，保留文本和基本格式
    """
    if not element:
        return ""
    
    # 移除标题元素
    title_elem = element.find('div', class_='section-title')
    if title_elem:
        title_elem.decompose()
    
    # 处理数学公式 (MathJax)
    math_elements = element.find_all(['script', 'span'], {'type': 'math/tex'})
    for math_elem in math_elements:
        if math_elem.string:
            math_elem.replace_with(f"${math_elem.string}$")
    
    # 处理MathJax span
    mathjax_spans = element.find_all('span', class_='MathJax')
    for span in mathjax_spans:
        # 尝试找到相关的script标签
        script = span.find_next('script', {'type': 'math/tex'})
        if script and script.string:
            span.replace_with(f"${script.string}$")
        else:
            # 如果没有找到，保留原文本
            span.replace_with(span.get_text())
    
    # 移除所有script标签
    for script in element.find_all('script'):
        script.decompose()
    
    # 获取文本内容
    text = element.get_text()
    
    # 清理多余的空白字符
    text = re.sub(r'\n\s*\n', '\n\n', text)
    text = re.sub(r' +', ' ', text)
    text = text.strip()
    
    return text

def extract_sample_tests(sample_tests_elem):
    """
    提取样例测试数据
    """
    samples = []
    sample_test_divs = sample_tests_elem.find_all('div', class_='sample-test')
    
    for i, sample_div in enumerate(sample_test_divs, 1):
        sample = {'number': i}
        
        # 输入
        input_div = sample_div.find('div', class_='input')
        if input_div:
            pre_elem = input_div.find('pre')
            if pre_elem:
                sample['input'] = pre_elem.get_text().strip()
        
        # 输出
        output_div = sample_div.find('div', class_='output')
        if output_div:
            pre_elem = output_div.find('pre')
            if pre_elem:
                sample['output'] = pre_elem.get_text().strip()
        
        samples.append(sample)
    
    return samples

def generate_markdown(problem_info, output_file):
    """
    生成Markdown文件
    """
    md_content = []
    
    # 标题
    if 'title' in problem_info:
        md_content.append(f"# {problem_info['title']}\n")
    
    # 基本信息
    md_content.append("## 题目信息\n")
    
    if 'time_limit' in problem_info:
        md_content.append(f"**时间限制**: {problem_info['time_limit']}")
    
    if 'memory_limit' in problem_info:
        md_content.append(f"**内存限制**: {problem_info['memory_limit']}")
    
    if 'input' in problem_info:
        md_content.append(f"**输入**: {problem_info['input']}")
    
    if 'output' in problem_info:
        md_content.append(f"**输出**: {problem_info['output']}")
    
    if 'difficulty' in problem_info:
        md_content.append(f"**难度**: {problem_info['difficulty']}")
    
    if 'tags' in problem_info and problem_info['tags']:
        tags_str = ", ".join(problem_info['tags'])
        md_content.append(f"**标签**: {tags_str}")
    
    md_content.append("")
    
    # 各个部分
    if 'sections' in problem_info:
        sections = problem_info['sections']
        
        # 题目描述
        if 'description' in sections:
            md_content.append("## 题目描述\n")
            md_content.append(sections['description'])
            md_content.append("")
        
        # 输入说明
        if 'input_specification' in sections:
            md_content.append("## 输入格式\n")
            md_content.append(sections['input_specification'])
            md_content.append("")
        
        # 输出说明
        if 'output_specification' in sections:
            md_content.append("## 输出格式\n")
            md_content.append(sections['output_specification'])
            md_content.append("")
        
        # 样例
        if 'sample_tests' in sections:
            md_content.append("## 样例\n")
            for sample in sections['sample_tests']:
                md_content.append(f"### 样例 {sample['number']}\n")
                
                if 'input' in sample:
                    md_content.append("**输入:**")
                    md_content.append("```")
                    md_content.append(sample['input'])
                    md_content.append("```\n")
                
                if 'output' in sample:
                    md_content.append("**输出:**")
                    md_content.append("```")
                    md_content.append(sample['output'])
                    md_content.append("```\n")
        
        # 注释
        if 'note' in sections:
            md_content.append("## 说明\n")
            md_content.append(sections['note'])
            md_content.append("")
    
    # 写入文件
    with open(output_file, 'w', encoding='utf-8') as f:
        f.write('\n'.join(md_content))

def process_single_file(html_file_path):
    """
    处理单个HTML文件
    """
    try:
        print(f"正在处理文件: {os.path.basename(html_file_path)}")
        
        # 提取题目信息
        problem_info = extract_problem_info(html_file_path)
        
        # 生成输出文件名（在原文件夹中）
        base_name = os.path.splitext(html_file_path)[0]
        output_file = f"{base_name}.md"
        
        # 生成Markdown文件
        generate_markdown(problem_info, output_file)
        
        print(f"✓ 成功生成: {os.path.basename(output_file)}")
        
        # 显示提取的信息摘要
        if 'title' in problem_info:
            print(f"  题目标题: {problem_info['title']}")
        if 'tags' in problem_info and problem_info['tags']:
            print(f"  标签: {', '.join(problem_info['tags'])}")
        
        return True
        
    except Exception as e:
        print(f"✗ 处理文件失败 {os.path.basename(html_file_path)}: {str(e)}")
        return False

def main():
    """
    主函数
    """
    # 指定目标文件夹
    target_folder = input("请输入要处理的文件夹路径: ").strip()
    
    # 检查文件夹是否存在
    if not os.path.exists(target_folder):
        print(f"错误：文件夹不存在 - {target_folder}")
        return
    
    print(f"开始遍历文件夹: {target_folder}")
    print("=" * 60)
    
    # 查找所有HTML文件
    html_files = []
    for root, dirs, files in os.walk(target_folder):
        for file in files:
            if file.lower().endswith('.html'):
                html_files.append(os.path.join(root, file))
    
    if not html_files:
        print("未找到任何HTML文件！")
        return
    
    print(f"找到 {len(html_files)} 个HTML文件")
    print("=" * 60)
    
    # 处理统计
    success_count = 0
    total_count = len(html_files)
    
    # 逐个处理文件
    for html_file in html_files:
        if process_single_file(html_file):
            success_count += 1
        print("-" * 40)
    
    # 显示处理结果
    print("=" * 60)
    print(f"处理完成！")
    print(f"总文件数: {total_count}")
    print(f"成功处理: {success_count}")
    print(f"失败数量: {total_count - success_count}")
    
    if success_count > 0:
        print(f"\n所有生成的Markdown文件已保存在原文件夹中")
    
    input("\n按回车键退出...")

if __name__ == "__main__":
    main()