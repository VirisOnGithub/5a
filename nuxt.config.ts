// https://nuxt.com/docs/api/configuration/nuxt-config
export default defineNuxtConfig({
  modules: ["@nuxt/content", "@nuxt/ui", "@nuxt/image"],
  css: ["~/assets/css/main.css", "katex/dist/katex.min.css"],
  devtools: { enabled: true },
  compatibilityDate: "2024-04-03",
  content: {
    build: {
      markdown: {
        remarkPlugins: {
          "remark-math": {},
        },
        rehypePlugins: {
          "rehype-katex": {
            output: "html",
          },
        },
      },
    },
  },
  runtimeConfig: {
    popoPassword: process.env.POPO
  }
});
