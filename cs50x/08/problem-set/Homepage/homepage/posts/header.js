const toc = document.createElement("div");
toc.classList.add("col-3", "toc");

const container = document.createElement("div");
container.classList.add("d-flex");

const vertical_rule = document.createElement("div");
vertical_rule.classList.add("vr");
container.appendChild(vertical_rule);

const headings = document.querySelector("content").querySelectorAll("h1, h2, h3, h4, h5, h6")
const nav = document.createElement("ul")
headings.forEach(heading => {
  const li = document.createElement("li");
  const a = document.createElement("a");

  heading.id = heading.innerText;
  a.href = `#${heading.innerText}`;
  a.innerText = heading.innerText;
  
  a.classList.add("text-reset", "text-decoration-none");
  li.classList.add("list-unstyled");

  li.appendChild(a);
  nav.appendChild(li);
})

container.appendChild(nav);
toc.appendChild(container);

content = document.querySelector("div.row");
content.querySelector("content").classList.add("col-9");
content.appendChild(toc);
