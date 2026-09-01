<script setup lang="ts">
import { PDFViewer } from "@embedpdf/vue-pdf-viewer";

const route = useRoute();
const { data: post } = await useAsyncData(route.path, () =>
    queryCollection("fifthyear").path(route.path).first(),
);

useSeoMeta({
    title: () => post.value?.title,
    description: () => post.value?.description,
    ...post.value?.seo,
});

definePageMeta({
    layout: "default",
});

watch(
    // terrorisme v2
    () => post.value,
    (newPost) => {
        const hasBody = newPost?.body?.value?.length !== 0;
        const hasPdf = Boolean(newPost?.pdfPath);

        if (hasBody && hasPdf) {
            setPageLayout("login");
        } else {
            setPageLayout("default");
        }
    },
    { immediate: true },
);
</script>

<template>
    <UButton
        v-if="post?.path"
        :to="getParentPath(post?.path)"
        class="p-2 m-2 border dark:border-white border-black bg-transparent dark:text-white text-black dark:hover:text-black dark:hover:bg-white"
    >
        &larr; Précédent
    </UButton>
    <div class="py-4"></div>
    <div v-if="post?.body.value.length !== 0">
        <div v-if="post?.pdfPath" class="flex min-h-screen">
            <div class="flex-1">
                <ContentRenderer v-if="post" :value="post" />
                <div v-else>Post not found</div>
            </div>
            <div class="h-screen flex-1">
                <ClientOnly>
                    <PDFViewer
                        :config="{
                            src: post.pdfPath,
                            tabBar: 'never',
                        }"
                        :style="{ width: '100%', height: '100%' }"
                    />
                </ClientOnly>
            </div>
        </div>
        <div v-else>
            <ContentRenderer v-if="post" :value="post" />
            <div v-else>Post not found</div>
        </div>
    </div>
    <div v-else-if="post?.pdfPath">
        <!-- <div style="height: 100vh"> -->
        <div class="h-screen">
            <ClientOnly>
                <PDFViewer
                    :config="{
                        src: '/pdf/INSI-TD1.pdf',
                        tabBar: 'never',
                    }"
                    :style="{ width: '100%', height: '100%' }"
                />
            </ClientOnly>
        </div>
    </div>
    <div v-else>
        <div class="text-center text-7xl">
            Un fichier PDF devrait être précisé, mais il n'a pas été fourni.
        </div>
    </div>
    <div class="py-4"></div>
    <!-- <pre><code>{{post}}</code></pre> -->
</template>
